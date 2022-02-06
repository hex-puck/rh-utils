#ifndef RH_UTILS_TYPE_SEQUENCE_H
#define RH_UTILS_TYPE_SEQUENCE_H

#include <rh-utils/meta/tuple.h>
#include <rh-utils/meta/type_at.h>
#include <utility>

namespace rh_utils {
namespace meta {
/**
 *  @brief a sequence of type, like `std::integer_sequence`
 *
 *  tuple seems for object usage, so use type_sequence for meta-programming.
 */
template <typename... Args> struct type_sequence {
  /**
   *  @brief make a new `type_sequence`
   *  @tparam Ints index pack of position of types which will be Args of new
   *    type_sequence
   */
  template <std::size_t... Ints> struct rebind {
    using other = type_sequence<type_at_t<Ints, Args...>...>;
  };

  /// @brief make sizeof...(Args)
  static constexpr std::size_t size() noexcept { return sizeof...(Args); }

  /**
   *  @brief extract type at the given position
   *  @tparam I position index
   */
  template <std::size_t I> using type = type_at_t<I, Args...>;
};

/**
 *  @brief make support for `type_sequence`
 *
 *  return type count of `type_sequence`
 */
template <typename... Args>
struct tuple_size<type_sequence<Args...>>
    : std::integral_constant<std::size_t, type_sequence<Args...>::size()> {};

/// @brief make support for `type_sequence`
template <std::size_t I, typename... Args>
struct tuple_element<I, type_sequence<Args...>> {
  using type = typename type_sequence<Args...>::template type<I>;
};

/// @brief make some type to `type_sequence`
template <typename> struct to_type_sequence;
/// @brief convenience type alias of `to_type_sequence`
template <typename T>
using to_type_sequence_t = typename to_type_sequence<T>::type;

template <typename... Args> struct to_type_sequence<tuple<Args...>> {
  using type = type_sequence<Args...>;
};

/// @brief make support for `type_sequence`
template <typename... Args> struct to_tuple<type_sequence<Args...>> {
  using type = tuple<Args...>;
};

namespace detail {
template <std::size_t, typename, typename>
struct type_sequence_splitter_helper {};
template <std::size_t I, typename T1, typename T2>
using type_sequence_splitter_helper_t =
    typename type_sequence_splitter_helper<I, T1, T2>::type;
template <std::size_t I, std::size_t... Ints, typename... Args>
struct type_sequence_splitter_helper<I, std::index_sequence<Ints...>,
                                     type_sequence<Args...>> {
  using type =
      typename type_sequence<Args...>::template rebind<(Ints + I)...>::other;
};
} // namespace detail

/**
 *  @brief primary template of `type_sequence_splitter`
 *  @note it's a no definition incomplete type.
 */
template <std::size_t, typename> struct type_sequence_splitter;
/**
 * @brief split the `type_sequence` into two sequence at given position
 * @tparam I index of split point
 */
template <std::size_t I, typename... Args>
struct type_sequence_splitter<I, type_sequence<Args...>> {
  /// @brief original type_sequence
  using origin = type_sequence<Args...>;
  /// @brief front-half result
  using front =
      detail::type_sequence_splitter_helper_t<0, std::make_index_sequence<I>,
                                              origin>;
  /// @brief back-half result
  using back = detail::type_sequence_splitter_helper_t<
      I, std::make_index_sequence<origin::size() - I>, origin>;
};
} // namespace meta
} // namespace rh_utils

#endif // RH_UTILS_TYPE_SEQUENCE_H
