#ifndef RH_UTILS_TUPLE_H
#define RH_UTILS_TUPLE_H

#include <tuple>

namespace rh_utils {
namespace meta {
/// @brief just std::tuple
using std::tuple;

/// @brief promoted version of std::tuple_size
template <typename T> struct tuple_size : std::tuple_size<T> {};
/// @brief promoted version of std::tuple_element
template <std::size_t I, typename T>
struct tuple_element : std::tuple_element<I, T> {};
/// @brief convenience type alias of `tuple_element`
template <std::size_t I, typename T>
using tuple_element_t = typename tuple_element<I, T>::type;

/// @brief make some type to tuple
template <typename> struct to_tuple;
/// @brief convenience type alias of `to_tuple`
template <typename T> using to_tuple_t = typename to_tuple<T>::type;
} // namespace meta
} // namespace rh_utils

#endif // RH_UTILS_TUPLE_H
