#ifndef RH_UTILS_TYPE_SEQUENCE_H
#define RH_UTILS_TYPE_SEQUENCE_H

namespace rh_utils {
    namespace meta {
        template<typename... Args>
        struct type_sequence
        {
            static constexpr std::size_t size() noexcept
            {
                return sizeof...(Args);
            }
        };
    }
}

#endif //RH_UTILS_TYPE_SEQUENCE_H
