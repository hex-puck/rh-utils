#ifndef RH_UTILS_TYPE_AT_H
#define RH_UTILS_TYPE_AT_H

namespace rh_utils {
    namespace meta {
        template<std::size_t I, typename... Args>
        struct type_at_index;

        template<std::size_t I, typename... Args>
        using type_at_index_t = typename type_at_index<I, Args...>::type;

        template<typename T, typename... Args>
        struct type_at_index<0, T, Args...> { using type = T; };

        template<std::size_t I, typename T, typename... Args>
        struct type_at_index<I, T, Args...>
        {
            static_assert(I < sizeof...(Args) + 1, "index is too large");
            using type = type_at_index_t<I - 1, Args...>;
        };
    }
}

#endif //RH_UTILS_TYPE_AT_H
