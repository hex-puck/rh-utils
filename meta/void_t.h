#ifndef RH_UTILS_VOID_T_H
#define RH_UTILS_VOID_T_H

#include <rh-utils/config.h>

#if RH_CXX_STANDARD >= 201703L
#include <type_traits>
#endif

namespace rh_utils {
    namespace meta {
#if RH_CXX_STANDARD < 201703L
        template<typename ...Args>
        using void_t = void;
#else
        template<typename ...Args>
        using void_t = std::void_t<Args...>;
#endif
    }
}

#endif //RH_UTILS_VOID_T_H
