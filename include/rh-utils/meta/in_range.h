#ifndef RH_UTILS_IN_RANGE_H
#define RH_UTILS_IN_RANGE_H

#include <limits>
#include <type_traits>

namespace rh_utils {
namespace meta {
namespace detail {
template <typename T, typename U> struct to_same_type : std::is_same<T, U> {};

template <typename T, typename U>
struct ui_to_ui_ge
    : std::integral_constant<
          bool, !std::is_same<T, U>::value && std::is_integral<T>::value &&
                    std::is_integral<U>::value && std::is_unsigned<T>::value &&
                    std::is_unsigned<U>::value && (sizeof(T) >= sizeof(U))> {};

template <typename T, typename U>
struct ui_to_ui_lt
    : std::integral_constant<
          bool, !std::is_same<T, U>::value && std::is_integral<T>::value &&
                    std::is_integral<U>::value && std::is_unsigned<T>::value &&
                    std::is_unsigned<U>::value && (sizeof(T) < sizeof(U))> {};

template <typename T, typename U>
struct si_to_si_ge
    : std::integral_constant<
          bool, !std::is_same<T, U>::value && std::is_integral<T>::value &&
                    std::is_integral<U>::value && std::is_signed<T>::value &&
                    std::is_signed<U>::value && (sizeof(T) >= sizeof(U))> {};

template <typename T, typename U>
struct si_to_si_lt
    : std::integral_constant<
          bool, !std::is_same<T, U>::value && std::is_integral<T>::value &&
                    std::is_integral<U>::value && std::is_signed<T>::value &&
                    std::is_signed<U>::value && (sizeof(T) < sizeof(U))> {};

template <typename T, typename U>
struct si_to_ui_ge
    : std::integral_constant<
          bool, !std::is_same<T, U>::value && std::is_integral<T>::value &&
                    std::is_integral<U>::value && std::is_unsigned<T>::value &&
                    std::is_signed<U>::value && (sizeof(T) >= sizeof(U))> {};

template <typename T, typename U>
struct si_to_ui_lt
    : std::integral_constant<
          bool, !std::is_same<T, U>::value && std::is_integral<T>::value &&
                    std::is_integral<U>::value && std::is_unsigned<T>::value &&
                    std::is_signed<U>::value && (sizeof(T) < sizeof(U))> {};

template <typename T, typename U>
struct ui_to_si_gt
    : std::integral_constant<
          bool, !std::is_same<T, U>::value && std::is_integral<T>::value &&
                    std::is_integral<U>::value && std::is_signed<T>::value &&
                    std::is_unsigned<U>::value && (sizeof(T) > sizeof(U))> {};

template <typename T, typename U>
struct ui_to_si_le
    : std::integral_constant<
          bool, !std::is_same<T, U>::value && std::is_integral<T>::value &&
                    std::is_integral<U>::value && std::is_signed<T>::value &&
                    std::is_unsigned<U>::value && (sizeof(T) <= sizeof(U))> {};
} // namespace detail

/**
 *  @brief judge is or not in_range when same type
 *  @tparam T target type
 *  @tparam U original type
 */
template <typename T, typename U>
constexpr std::enable_if_t<detail::to_same_type<T, U>::value, bool>
in_range(U /*v*/) noexcept {
  return true;
}

/**
 *  @brief judge is or not in_range between unsigned integer type
 *  @note only enabled when `sizeof(T) >= sizeof(U)`
 *  @tparam T target type, should be unsigned integer type
 *  @tparam U original type, should be unsigned integer type
 */
template <typename T, typename U>
constexpr std::enable_if_t<detail::ui_to_ui_ge<T, U>::value, bool>
in_range(U /*v*/) noexcept {
  static_assert(std::numeric_limits<T>::lowest() <=
                    std::numeric_limits<U>::lowest(),
                "should be true");
  static_assert(std::numeric_limits<U>::max() <= std::numeric_limits<T>::max(),
                "should be true");
  return true;
}

/**
 *  @brief judge is or not in_range between unsigned integer type
 *  @note only enabled when `sizeof(T) < sizeof(U)`
 *  @tparam T target type, should be unsigned integer type
 *  @tparam U original type, should be unsigned integer type
 */
template <typename T, typename U>
constexpr std::enable_if_t<detail::ui_to_ui_lt<T, U>::value, bool>
in_range(U v) noexcept {
  static_assert(std::numeric_limits<T>::lowest() <=
                    std::numeric_limits<U>::lowest(),
                "should be true");
  return v <= std::numeric_limits<T>::max();
}

/**
 *  @brief judge is or not in_range between signed integer type
 *  @note only enabled when `sizeof(T) >= sizeof(U)`
 *  @tparam T target type, should be signed integer type
 *  @tparam U original type, should be signed integer type
 */
template <typename T, typename U>
constexpr std::enable_if_t<detail::si_to_si_ge<T, U>::value, bool>
in_range(U /*v*/) noexcept {
  static_assert(std::numeric_limits<T>::lowest() <=
                    std::numeric_limits<U>::lowest(),
                "should be true");
  static_assert(std::numeric_limits<U>::max() <= std::numeric_limits<T>::max(),
                "should be true");
  return true;
}

/**
 *  @brief judge is or not in_range between signed integer type
 *  @note only enabled when `sizeof(T) < sizeof(U)`
 *  @tparam T target type, should be signed integer type
 *  @tparam U original type, should be signed integer type
 */
template <typename T, typename U>
constexpr std::enable_if_t<detail::si_to_si_lt<T, U>::value, bool>
in_range(U v) noexcept {
  return std::numeric_limits<T>::lowest() <= v &&
         v <= std::numeric_limits<T>::max();
}

/**
 *  @brief judge is or not in_range when signed to unsigned
 *  @note only enabled when `sizeof(T) >= sizeof(U)`
 *  @tparam T target type, should be unsigned integer type
 *  @tparam U original type, should be signed integer type
 */
template <typename T, typename U>
constexpr std::enable_if_t<detail::si_to_ui_ge<T, U>::value, bool>
in_range(U v) noexcept {
  static_assert(
      static_cast<std::make_unsigned_t<U>>(std::numeric_limits<U>::max()) <=
          std::numeric_limits<T>::max(),
      "should be true");
  return static_cast<std::make_signed_t<T>>(std::numeric_limits<T>::lowest()) <=
         v;
}

/**
 *  @brief judge is or not in_range when signed to unsigned
 *  @note only enabled when `sizeof(T) < sizeof(U)`
 *  @tparam T target type, should be unsigned integer type
 *  @tparam U original type, should be signed integer type
 */
template <typename T, typename U>
constexpr std::enable_if_t<detail::si_to_ui_lt<T, U>::value, bool>
in_range(U v) noexcept {
  if (static_cast<std::make_signed_t<T>>(std::numeric_limits<T>::lowest()) <=
      v) {
    return static_cast<std::make_unsigned_t<U>>(v) <=
           std::numeric_limits<T>::max();
  }
  return false;
}

/**
 *  @brief judge is or not in_range when unsigned to signed
 *  @note only enabled when `sizeof(T) > sizeof(U)`
 *  @tparam T target type, should be signed integer type
 *  @tparam U original type, should be unsigned integer type
 */
template <typename T, typename U>
constexpr std::enable_if_t<detail::ui_to_si_gt<T, U>::value, bool>
in_range(U /*v*/) noexcept {
  static_assert(
      std::numeric_limits<T>::lowest() <=
          static_cast<std::make_signed_t<U>>(std::numeric_limits<U>::lowest()),
      "should be true");
  static_assert(
      std::numeric_limits<U>::max() <=
          static_cast<std::make_unsigned_t<T>>(std::numeric_limits<T>::max()),
      "should be true");
  return true;
}

/**
 *  @brief judge is or not in_range when unsigned to signed
 *  @note only enabled when `sizeof(T) <= sizeof(U)`
 *  @tparam T target type, should be signed integer type
 *  @tparam U original type, should be unsigned integer type
 */
template <typename T, typename U>
constexpr std::enable_if_t<detail::ui_to_si_le<T, U>::value, bool>
in_range(U v) noexcept {
  static_assert(
      std::numeric_limits<T>::lowest() <=
          static_cast<std::make_signed_t<U>>(std::numeric_limits<U>::lowest()),
      "should be true");
  return v <=
         static_cast<std::make_unsigned_t<T>>(std::numeric_limits<T>::max());
}
} // namespace meta
} // namespace rh_utils

#endif // RH_UTILS_IN_RANGE_H
