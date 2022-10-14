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

/**
 *  @brief Check if type is variadic function type
 */
template <typename> struct is_variadic_function : std::false_type {};

#if RH_CXX_STANDARD >= 201703L
template <typename T>
inline constexpr bool is_variadic_function_v = is_variadic_function<T>::value;
#endif

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

#define RH_UTILS_LOCAL_DEFINE_IVF_true(Amend_, Variadic_)                      \
  template <typename Ret, typename... Args>                                    \
  struct is_variadic_function<Ret(Args..., ...) Amend_> : std::true_type {};
#define RH_UTILS_LOCAL_DEFINE_IVF_false(Amend_, Variadic_) // empty

#define RH_UTILS_LOCAL_DEFINE_IVF(Amend_, Variadic_)                           \
  RH_UTILS_LOCAL_DEFINE_IVF_##Variadic_(Amend_, Variadic_)

#define RH_UTILS_LOCAL_DEFINE(Amend_, Variadic_)                               \
  RH_UTILS_LOCAL_DEFINE_FI(Amend_, Variadic_)                                  \
  RH_UTILS_LOCAL_DEFINE_IVF(Amend_, Variadic_)

RH_UTILS_LOCAL_DEFINE(, false)
RH_UTILS_LOCAL_DEFINE(, true)

RH_UTILS_LOCAL_DEFINE(const, false)
RH_UTILS_LOCAL_DEFINE(volatile, false)
RH_UTILS_LOCAL_DEFINE(const volatile, false)

RH_UTILS_LOCAL_DEFINE(const, true)
RH_UTILS_LOCAL_DEFINE(volatile, true)
RH_UTILS_LOCAL_DEFINE(const volatile, true)

#if RH_CXX_STANDARD >= 201103L
RH_UTILS_LOCAL_DEFINE(&, false)
RH_UTILS_LOCAL_DEFINE(const &, false)
RH_UTILS_LOCAL_DEFINE(volatile &, false)
RH_UTILS_LOCAL_DEFINE(const volatile &, false)

RH_UTILS_LOCAL_DEFINE(&, true)
RH_UTILS_LOCAL_DEFINE(const &, true)
RH_UTILS_LOCAL_DEFINE(volatile &, true)
RH_UTILS_LOCAL_DEFINE(const volatile &, true)

RH_UTILS_LOCAL_DEFINE(&&, false)
RH_UTILS_LOCAL_DEFINE(const &&, false)
RH_UTILS_LOCAL_DEFINE(volatile &&, false)
RH_UTILS_LOCAL_DEFINE(const volatile &&, false)

RH_UTILS_LOCAL_DEFINE(&&, true)
RH_UTILS_LOCAL_DEFINE(const &&, true)
RH_UTILS_LOCAL_DEFINE(volatile &&, true)
RH_UTILS_LOCAL_DEFINE(const volatile &&, true)
#endif

#if RH_CXX_STANDARD >= 201703L
RH_UTILS_LOCAL_DEFINE(noexcept, false)
RH_UTILS_LOCAL_DEFINE(noexcept, true)

RH_UTILS_LOCAL_DEFINE(const noexcept, false)
RH_UTILS_LOCAL_DEFINE(volatile noexcept, false)
RH_UTILS_LOCAL_DEFINE(const volatile noexcept, false)

RH_UTILS_LOCAL_DEFINE(const noexcept, true)
RH_UTILS_LOCAL_DEFINE(volatile noexcept, true)
RH_UTILS_LOCAL_DEFINE(const volatile noexcept, true)

RH_UTILS_LOCAL_DEFINE(&noexcept, false)
RH_UTILS_LOCAL_DEFINE(const &noexcept, false)
RH_UTILS_LOCAL_DEFINE(volatile &noexcept, false)
RH_UTILS_LOCAL_DEFINE(const volatile &noexcept, false)

RH_UTILS_LOCAL_DEFINE(&noexcept, true)
RH_UTILS_LOCAL_DEFINE(const &noexcept, true)
RH_UTILS_LOCAL_DEFINE(volatile &noexcept, true)
RH_UTILS_LOCAL_DEFINE(const volatile &noexcept, true)

RH_UTILS_LOCAL_DEFINE(&&noexcept, false)
RH_UTILS_LOCAL_DEFINE(const &&noexcept, false)
RH_UTILS_LOCAL_DEFINE(volatile &&noexcept, false)
RH_UTILS_LOCAL_DEFINE(const volatile &&noexcept, false)

RH_UTILS_LOCAL_DEFINE(&&noexcept, true)
RH_UTILS_LOCAL_DEFINE(const &&noexcept, true)
RH_UTILS_LOCAL_DEFINE(volatile &&noexcept, true)
RH_UTILS_LOCAL_DEFINE(const volatile &&noexcept, true)
#endif

#undef RH_UTILS_LOCAL_FI_COMMON_MEMBER
#undef RH_UTILS_LOCAL_DEFINE_FI_FT_true
#undef RH_UTILS_LOCAL_DEFINE_FI_FT_false
#undef RH_UTILS_LOCAL_DEFINE_FI
#undef RH_UTILS_LOCAL_DEFINE_IVF_true
#undef RH_UTILS_LOCAL_DEFINE_IVF_false
#undef RH_UTILS_LOCAL_DEFINE_IVF
#undef RH_UTILS_LOCAL_DEFINE
} // namespace meta
} // namespace rh_utils

#endif // RH_UTILS_FUNCTION_INFO_H
