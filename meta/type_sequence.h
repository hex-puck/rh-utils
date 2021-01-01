#ifndef RH_UTILS_TYPE_SEQUENCE_H
#define RH_UTILS_TYPE_SEQUENCE_H

#include <rh-utils/meta/type_at.h>

namespace rh_utils {
    namespace meta {
        template<typename... Args>
        struct type_sequence
        {
            static constexpr std::size_t size() noexcept
            {
                return sizeof...(Args);
            }

            template<std::size_t I>
            using type = type_at_t<I, Args...>;
        };
    }
}

#endif //RH_UTILS_TYPE_SEQUENCE_H
