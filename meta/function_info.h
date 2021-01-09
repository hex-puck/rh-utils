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
    }
}

#endif //RH_UTILS_FUNCTION_INFO_H
