#ifndef RH_UTILS_MEMBER_POINTER_INFO_H
#define RH_UTILS_MEMBER_POINTER_INFO_H

#include <type_traits>

namespace rh_utils {
namespace meta {
namespace detail {
template <typename> struct member_pointer_info_helper;

template <typename T, typename U> struct member_pointer_info_helper<T U::*> {
  using pointed_type = T;
  using owner_type = U;
};
} // namespace detail

template <typename T>
struct member_pointer_info
    : detail::member_pointer_info_helper<std::remove_cv_t<T>> {};
} // namespace meta
} // namespace rh_utils

#endif // RH_UTILS_MEMBER_POINTER_INFO_H
