#ifndef RH_UTILS_TUPLE_H
#define RH_UTILS_TUPLE_H

#include <tuple>

namespace rh_utils {
namespace meta {
template <typename... Args> using tuple = std::tuple<Args...>;

template <typename T> struct tuple_size : public std::tuple_size<T> {};
template <std::size_t I, typename T>
struct tuple_element : public std::tuple_element<I, T> {};
template <std::size_t I, typename T>
using tuple_element_t = typename tuple_element<I, T>::type;

template <typename> struct to_tuple;
template <typename T> using to_tuple_t = typename to_tuple<T>::type;
} // namespace meta
} // namespace rh_utils

#endif // RH_UTILS_TUPLE_H
