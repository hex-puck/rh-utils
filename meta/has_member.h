#ifndef RH_UTILS_HAS_MEMBER_H
#define RH_UTILS_HAS_MEMBER_H

#include <type_traits>
#include <utility>
#include <rh-utils/meta/void_t.h>

#define RH_HAS_MEMBER(Member)                                                                                 \
namespace rh_utils {                                                                                          \
    namespace meta {                                                                                          \
        template<typename, typename = void>                                                                   \
        struct has_member_##Member : public std::false_type {};                                               \
                                                                                                              \
        template<typename C>                                                                                  \
        struct has_member_##Member<C, void_t<decltype(std::declval<C>().Member)>> : public std::true_type {}; \
    }                                                                                                         \
}

#endif //RH_UTILS_HAS_MEMBER_H
