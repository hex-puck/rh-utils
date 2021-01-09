#ifndef RH_UTILS_FUNCTION_INFO_H
#define RH_UTILS_FUNCTION_INFO_H

#include <type_traits>
#include <rh-utils/config.h>
#include <rh-utils/meta/type_sequence.h>

namespace rh_utils {
    namespace meta {
        template<typename>
        struct function_info;

        template<typename R, typename ...Args>
        struct function_info<R(Args...)>
        {
            using type = R(std::decay_t<Args>...);
            using parameter_sequence = type_sequence<std::decay_t<Args>...>;

            template<std::size_t I>
            using parameter_type = typename parameter_sequence::template type<I>;
            using return_type = R;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...)>
                : public function_info<R(Args...)>
        {
            using class_type = C;
            using type = R(C::*)(std::decay_t<Args>...);
            using bare_type = typename function_info<R(Args...)>::type;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) const>
                : public function_info<R(C::*)(Args...)>
        {
            using type = R(C::*)(std::decay_t<Args>...) const;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) volatile>
                : public function_info<R(C::*)(Args...)>
        {
            using type = R(C::*)(std::decay_t<Args>...) volatile;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) const volatile>
                : public function_info<R(C::*)(Args...)>
        {
            using type = R(C::*)(std::decay_t<Args>...) const volatile;
        };

#if RH_CXX_STANDARD >= 201103L
        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) &>
                : public function_info<R(C::*)(Args...)>
        {
            using type = R(C::*)(std::decay_t<Args>...) &;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) const &>
                : public function_info<R(C::*)(Args...)>
        {
            using type = R(C::*)(std::decay_t<Args>...) const &;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) volatile &>
                : public function_info<R(C::*)(Args...)>
        {
            using type = R(C::*)(std::decay_t<Args>...) volatile &;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) const volatile &>
                : public function_info<R(C::*)(Args...)>
        {
            using type = R(C::*)(std::decay_t<Args>...) const volatile &;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) &&>
                : public function_info<R(C::*)(Args...)>
        {
            using type = R(C::*)(std::decay_t<Args>...) &&;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) const &&>
                : public function_info<R(C::*)(Args...)>
        {
            using type = R(C::*)(std::decay_t<Args>...) const &&;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) volatile &&>
                : public function_info<R(C::*)(Args...)>
        {
            using type = R(C::*)(std::decay_t<Args>...) volatile &&;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) const volatile &&>
                : public function_info<R(C::*)(Args...)>
        {
            using type = R(C::*)(std::decay_t<Args>...) const volatile &&;
        };
#endif
#if RH_CXX_STANDARD >= 201703L
        template<typename R, typename ...Args>
        struct function_info<R(Args...) noexcept>
                : public function_info<R(Args...)>
        {
            using type = R(std::decay_t<Args>...) noexcept;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) noexcept>
                : public function_info<R(Args...) noexcept>
        {
            using class_type = C;
            using type = R(C::*)(std::decay_t<Args>...) noexcept;
            using bare_type = typename function_info<R(Args...) noexcept>::type;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) const noexcept>
                : public function_info<R(C::*)(Args...) noexcept>
        {
            using type = R(C::*)(std::decay_t<Args>...) const noexcept;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) volatile noexcept>
                : public function_info<R(C::*)(Args...) noexcept>
        {
            using type = R(C::*)(std::decay_t<Args>...) volatile noexcept;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) const volatile noexcept>
                : public function_info<R(C::*)(Args...) noexcept>
        {
            using type = R(C::*)(std::decay_t<Args>...) const volatile noexcept;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) &noexcept>
                : public function_info<R(C::*)(Args...) noexcept>
        {
            using type = R(C::*)(std::decay_t<Args>...) &noexcept;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) const &noexcept>
                : public function_info<R(C::*)(Args...) noexcept>
        {
            using type = R(C::*)(std::decay_t<Args>...) const &noexcept;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) volatile &noexcept>
                : public function_info<R(C::*)(Args...) noexcept>
        {
            using type = R(C::*)(std::decay_t<Args>...) volatile &noexcept;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) const volatile &noexcept>
                : public function_info<R(C::*)(Args...) noexcept>
        {
            using type = R(C::*)(std::decay_t<Args>...) const volatile &noexcept;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) &&noexcept>
                : public function_info<R(C::*)(Args...) noexcept>
        {
            using type = R(C::*)(std::decay_t<Args>...) &&noexcept;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) const &&noexcept>
                : public function_info<R(C::*)(Args...) noexcept>
        {
            using type = R(C::*)(std::decay_t<Args>...) const &&noexcept;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) volatile &&noexcept>
                : public function_info<R(C::*)(Args...) noexcept>
        {
            using type = R(C::*)(std::decay_t<Args>...) volatile &&noexcept;
        };

        template<typename C, typename R, typename ...Args>
        struct function_info<R(C::*)(Args...) const volatile &&noexcept>
                : public function_info<R(C::*)(Args...) noexcept>
        {
            using type = R(C::*)(std::decay_t<Args>...) const volatile &&noexcept;
        };
#endif
    }
}

#endif //RH_UTILS_FUNCTION_INFO_H
