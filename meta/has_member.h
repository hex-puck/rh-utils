#ifndef RH_UTILS_HAS_MEMBER_H
#define RH_UTILS_HAS_MEMBER_H

#include <type_traits>
#include <utility>
#include <rh-utils/meta/void_t.h>

#define RH_HAS_MEMBER_OBJECT(Member)                                                                                 \
namespace rh_utils {                                                                                                 \
    namespace meta {                                                                                                 \
        template<typename, typename = void>                                                                          \
        struct has_member_object_##Member : public std::false_type {};                                               \
                                                                                                                     \
        template<typename C>                                                                                         \
        struct has_member_object_##Member<C, void_t<decltype(std::declval<C>().Member)>> : public std::true_type {}; \
    }                                                                                                                \
}

#define RH_HAS_MEMBER_FUNCTION(Member)                                                                    \
namespace rh_utils {                                                                                      \
    namespace meta {                                                                                      \
        template<typename C, typename ...Args>                                                            \
        struct has_member_function_##Member                                                               \
        {                                                                                                 \
        private:                                                                                          \
            template<typename U, typename ...Args0>                                                       \
            static std::true_type invoke(decltype(std::declval<U>().Member(std::declval<Args0>()...)) *); \
            template<typename ...>                                                                        \
            static std::false_type invoke(...);                                                           \
        public:                                                                                           \
            enum { value = decltype(invoke<C, Args...>(nullptr))::value };                                \
        };                                                                                                \
    }                                                                                                     \
}

#endif //RH_UTILS_HAS_MEMBER_H
