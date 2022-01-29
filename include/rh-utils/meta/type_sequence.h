#ifndef RH_UTILS_TYPE_SEQUENCE_H
#define RH_UTILS_TYPE_SEQUENCE_H

#include <rh-utils/meta/tuple.h>
#include <rh-utils/meta/type_at.h>

namespace rh_utils {
namespace meta {
template <typename... Args> struct type_sequence {
  static constexpr std::size_t size() noexcept { return sizeof...(Args); }

  template <std::size_t I> using type = type_at_t<I, Args...>;
};

template <typename... Args>
struct tuple_size<type_sequence<Args...>>
    : std::integral_constant<std::size_t, type_sequence<Args...>::size()> {};

template <std::size_t I, typename... Args>
struct tuple_element<I, type_sequence<Args...>> {
  using type = typename type_sequence<Args...>::template type<I>;
};

template <typename> struct to_type_sequence;
template <typename T>
using to_type_sequence_t = typename to_type_sequence<T>::type;

template <typename... Args> struct to_type_sequence<tuple<Args...>> {
  using type = type_sequence<Args...>;
};

template <typename... Args> struct to_tuple<type_sequence<Args...>> {
  using type = tuple<Args...>;
};
} // namespace meta
} // namespace rh_utils

#endif // RH_UTILS_TYPE_SEQUENCE_H
