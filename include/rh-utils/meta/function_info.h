#ifndef RH_UTILS_FUNCTION_INFO_H
#define RH_UTILS_FUNCTION_INFO_H

#include <rh-utils/config.h>
#include <rh-utils/meta/type_sequence.h>
#include <type_traits>

namespace rh_utils {
namespace meta {
/**
 *  @brief Parse function and member function pointer type
 *
 *  Primary template is undefined. See other specialization for more information
 */
template <typename> struct function_info;

/**
 *  @brief Parse function type
 *  @tparam R return type of function
 *  @tparam Args package of parameter types of function
 */
template <typename R, typename... Args> struct function_info<R(Args...)> {
  /// @brief the given function type
  using type = R(std::decay_t<Args>...);
  /**
   *  @brief type_sequence of parameter types of `type`
   *  @sa @ref type_sequence
   */
  using parameter_sequence = type_sequence<std::decay_t<Args>...>;

  /**
   *  @brief parameter type at given position
   *  @tparam I parameter index
   */
  template <std::size_t I>
  using parameter_type = typename parameter_sequence::template type<I>;
  /// @brief return type of `type`
  using return_type = R;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...)> : public function_info<R(Args...)> {
  /// @brief owner class
  using class_type = C;
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...);
  /// @brief regular function type of `type`
  using bare_type = typename function_info<R(Args...)>::type;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) const>
    : public function_info<R (C::*)(Args...)> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) const;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) volatile>
    : public function_info<R (C::*)(Args...)> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) volatile;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) const volatile>
    : public function_info<R (C::*)(Args...)> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) const volatile;
};

#if RH_CXX_STANDARD >= 201103L
/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) &>
    : public function_info<R (C::*)(Args...)> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) &;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) const &>
    : public function_info<R (C::*)(Args...)> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) const &;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) volatile &>
    : public function_info<R (C::*)(Args...)> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) volatile &;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) const volatile &>
    : public function_info<R (C::*)(Args...)> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) const volatile &;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) &&>
    : public function_info<R (C::*)(Args...)> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) &&;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) const &&>
    : public function_info<R (C::*)(Args...)> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) const &&;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) volatile &&>
    : public function_info<R (C::*)(Args...)> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) volatile &&;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) const volatile &&>
    : public function_info<R (C::*)(Args...)> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) const volatile &&;
};
#endif
#if RH_CXX_STANDARD >= 201703L
/**
 *  @brief Parse function info
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename R, typename... Args>
struct function_info<R(Args...) noexcept> : public function_info<R(Args...)> {
  /// @brief member function pointer type
  using type = R(std::decay_t<Args>...) noexcept;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) noexcept>
    : public function_info<R(Args...) noexcept> {
  /// @brief owner class
  using class_type = C;
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) noexcept;
  /// @brief regular function type of `type`
  using bare_type = typename function_info<R(Args...) noexcept>::type;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) const noexcept>
    : public function_info<R (C::*)(Args...) noexcept> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) const noexcept;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) volatile noexcept>
    : public function_info<R (C::*)(Args...) noexcept> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) volatile noexcept;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) const volatile noexcept>
    : public function_info<R (C::*)(Args...) noexcept> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) const volatile noexcept;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) &noexcept>
    : public function_info<R (C::*)(Args...) noexcept> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) &noexcept;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) const &noexcept>
    : public function_info<R (C::*)(Args...) noexcept> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) const &noexcept;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) volatile &noexcept>
    : public function_info<R (C::*)(Args...) noexcept> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) volatile &noexcept;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) const volatile &noexcept>
    : public function_info<R (C::*)(Args...) noexcept> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) const volatile &noexcept;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) &&noexcept>
    : public function_info<R (C::*)(Args...) noexcept> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) &&noexcept;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) const &&noexcept>
    : public function_info<R (C::*)(Args...) noexcept> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) const &&noexcept;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) volatile &&noexcept>
    : public function_info<R (C::*)(Args...) noexcept> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) volatile &&noexcept;
};

/**
 *  @brief Parse member function pointer info
 *  @tparam C owner class
 *  @tparam R return type of member function
 *  @tparam Args package of parameter types of member function
 */
template <typename C, typename R, typename... Args>
struct function_info<R (C::*)(Args...) const volatile &&noexcept>
    : public function_info<R (C::*)(Args...) noexcept> {
  /// @brief member function pointer type
  using type = R (C::*)(std::decay_t<Args>...) const volatile &&noexcept;
};
#endif
} // namespace meta
} // namespace rh_utils

#endif // RH_UTILS_FUNCTION_INFO_H
