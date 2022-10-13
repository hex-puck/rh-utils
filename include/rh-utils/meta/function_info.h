#ifndef RH_UTILS_FUNCTION_INFO_H
#define RH_UTILS_FUNCTION_INFO_H

#include <rh-utils/config.h>
#include <rh-utils/meta/type_sequence.h>
#include <type_traits>

namespace rh_utils {
namespace meta {
/**
 *  @brief Parse function and member function type
 */
template <typename> struct function_info;

#define RH_UTILS_LOCAL_FI_COMMON_MEMBER(Ret_, Args_)                           \
  using return_type = Ret_;                                                    \
  using parameter_sequence = type_sequence<Args_...>;                          \
  template <std::size_t I>                                                     \
  using parameter_type = typename parameter_sequence::template type<I>;

#define RH_UTILS_LOCAL_DEFINE_FI_FT_true(Ret_, Args_) Ret_(Args_..., ...)
#define RH_UTILS_LOCAL_DEFINE_FI_FT_false(Ret_, Args_) Ret_(Args_...)

#define RH_UTILS_LOCAL_DEFINE_FI(Amend_, Variadic_)                            \
  template <typename Ret, typename... Args>                                    \
  struct function_info<RH_UTILS_LOCAL_DEFINE_FI_FT_##Variadic_(Ret, Args)      \
                           Amend_> {                                           \
    using type = RH_UTILS_LOCAL_DEFINE_FI_FT_##Variadic_(Ret, Args) Amend_;    \
    RH_UTILS_LOCAL_FI_COMMON_MEMBER(Ret, Args)                                 \
  };

RH_UTILS_LOCAL_DEFINE_FI(, false)
RH_UTILS_LOCAL_DEFINE_FI(, true)

RH_UTILS_LOCAL_DEFINE_FI(const, false)
RH_UTILS_LOCAL_DEFINE_FI(volatile, false)
RH_UTILS_LOCAL_DEFINE_FI(const volatile, false)

RH_UTILS_LOCAL_DEFINE_FI(const, true)
RH_UTILS_LOCAL_DEFINE_FI(volatile, true)
RH_UTILS_LOCAL_DEFINE_FI(const volatile, true)

#if RH_CXX_STANDARD >= 201103L
RH_UTILS_LOCAL_DEFINE_FI(&, false)
RH_UTILS_LOCAL_DEFINE_FI(const &, false)
RH_UTILS_LOCAL_DEFINE_FI(volatile &, false)
RH_UTILS_LOCAL_DEFINE_FI(const volatile &, false)

RH_UTILS_LOCAL_DEFINE_FI(&, true)
RH_UTILS_LOCAL_DEFINE_FI(const &, true)
RH_UTILS_LOCAL_DEFINE_FI(volatile &, true)
RH_UTILS_LOCAL_DEFINE_FI(const volatile &, true)

RH_UTILS_LOCAL_DEFINE_FI(&&, false)
RH_UTILS_LOCAL_DEFINE_FI(const &&, false)
RH_UTILS_LOCAL_DEFINE_FI(volatile &&, false)
RH_UTILS_LOCAL_DEFINE_FI(const volatile &&, false)

RH_UTILS_LOCAL_DEFINE_FI(&&, true)
RH_UTILS_LOCAL_DEFINE_FI(const &&, true)
RH_UTILS_LOCAL_DEFINE_FI(volatile &&, true)
RH_UTILS_LOCAL_DEFINE_FI(const volatile &&, true)
#endif

#if RH_CXX_STANDARD >= 201703L
RH_UTILS_LOCAL_DEFINE_FI(noexcept, false)
RH_UTILS_LOCAL_DEFINE_FI(noexcept, true)

RH_UTILS_LOCAL_DEFINE_FI(const noexcept, false)
RH_UTILS_LOCAL_DEFINE_FI(volatile noexcept, false)
RH_UTILS_LOCAL_DEFINE_FI(const volatile noexcept, false)

RH_UTILS_LOCAL_DEFINE_FI(const noexcept, true)
RH_UTILS_LOCAL_DEFINE_FI(volatile noexcept, true)
RH_UTILS_LOCAL_DEFINE_FI(const volatile noexcept, true)

RH_UTILS_LOCAL_DEFINE_FI(&noexcept, false)
RH_UTILS_LOCAL_DEFINE_FI(const &noexcept, false)
RH_UTILS_LOCAL_DEFINE_FI(volatile &noexcept, false)
RH_UTILS_LOCAL_DEFINE_FI(const volatile &noexcept, false)

RH_UTILS_LOCAL_DEFINE_FI(&noexcept, true)
RH_UTILS_LOCAL_DEFINE_FI(const &noexcept, true)
RH_UTILS_LOCAL_DEFINE_FI(volatile &noexcept, true)
RH_UTILS_LOCAL_DEFINE_FI(const volatile &noexcept, true)

RH_UTILS_LOCAL_DEFINE_FI(&&noexcept, false)
RH_UTILS_LOCAL_DEFINE_FI(const &&noexcept, false)
RH_UTILS_LOCAL_DEFINE_FI(volatile &&noexcept, false)
RH_UTILS_LOCAL_DEFINE_FI(const volatile &&noexcept, false)

RH_UTILS_LOCAL_DEFINE_FI(&&noexcept, true)
RH_UTILS_LOCAL_DEFINE_FI(const &&noexcept, true)
RH_UTILS_LOCAL_DEFINE_FI(volatile &&noexcept, true)
RH_UTILS_LOCAL_DEFINE_FI(const volatile &&noexcept, true)
#endif

#undef RH_UTILS_LOCAL_FI_COMMON_MEMBER
#undef RH_UTILS_LOCAL_DEFINE_FI_FT_true
#undef RH_UTILS_LOCAL_DEFINE_FI_FT_false
#undef RH_UTILS_LOCAL_DEFINE_FI
} // namespace meta
} // namespace rh_utils

#endif // RH_UTILS_FUNCTION_INFO_H
