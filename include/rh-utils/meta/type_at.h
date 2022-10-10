#ifndef RH_UTILS_TYPE_AT_H
#define RH_UTILS_TYPE_AT_H

#include <cstddef>

namespace rh_utils {
namespace meta {
/// @brief extract type at the given position
template <std::size_t I, typename... Args> struct type_at;
/// @brief convenience type alias of `type_at`
template <std::size_t I, typename... Args>
using type_at_t = typename type_at<I, Args...>::type;

template <typename T, typename... Args> struct type_at<0, T, Args...> {
  using type = T;
};

template <std::size_t I, typename T, typename... Args>
struct type_at<I, T, Args...> {
  using type = type_at_t<I - 1, Args...>;
};
} // namespace meta
} // namespace rh_utils

#endif // RH_UTILS_TYPE_AT_H
