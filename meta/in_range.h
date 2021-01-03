#ifndef RH_UTILS_IN_RANGE_H
#define RH_UTILS_IN_RANGE_H

#include <type_traits>
#include <limits>

namespace rh_utils {
    namespace meta {
        // convert between same type
        template<typename T, typename U, std::enable_if_t<
                std::is_same<T, U>::value
        > * = nullptr>
        constexpr bool in_range(U /*v*/) { return true; }

        // convert between unsigned integral
        template<typename T, typename U, std::enable_if_t<
                !std::is_same<T, U>::value
                && std::is_integral<T>::value && std::is_integral<U>::value
                && std::is_unsigned<T>::value && std::is_unsigned<U>::value
                && (sizeof(T) >= sizeof(U))
        > * = nullptr>
        constexpr bool in_range(U /*v*/)
        {
            static_assert(std::numeric_limits<T>::lowest() <= std::numeric_limits<U>::lowest(), "should be true");
            static_assert(std::numeric_limits<U>::max() <= std::numeric_limits<T>::max(), "should be true");
            return true;
        }

        template<typename T, typename U, std::enable_if_t<
                !std::is_same<T, U>::value
                && std::is_integral<T>::value && std::is_integral<U>::value
                && std::is_unsigned<T>::value && std::is_unsigned<U>::value
                && (sizeof(T) < sizeof(U))
        > * = nullptr>
        constexpr bool in_range(U v)
        {
            static_assert(std::numeric_limits<T>::lowest() <= std::numeric_limits<U>::lowest(), "should be true");
            return v <= std::numeric_limits<T>::max();
        }

        // convert between signed integral
        template<typename T, typename U, std::enable_if_t<
                !std::is_same<T, U>::value
                && std::is_integral<T>::value && std::is_integral<U>::value
                && std::is_signed<T>::value && std::is_signed<U>::value
                && (sizeof(T) >= sizeof(U))
        > * = nullptr>
        constexpr bool in_range(U /*v*/)
        {
            static_assert(std::numeric_limits<T>::lowest() <= std::numeric_limits<U>::lowest(), "should be true");
            static_assert(std::numeric_limits<U>::max() <= std::numeric_limits<T>::max(), "should be true");
            return true;
        }

        template<typename T, typename U, std::enable_if_t<
                !std::is_same<T, U>::value
                && std::is_integral<T>::value && std::is_integral<U>::value
                && std::is_signed<T>::value && std::is_signed<U>::value
                && (sizeof(T) < sizeof(U))
        > * = nullptr>
        constexpr bool in_range(U v)
        {
            return std::numeric_limits<T>::lowest() <= v
                   && v <= std::numeric_limits<T>::max();
        }

        // convert signed integral to unsigned integral
        template<typename T, typename U, std::enable_if_t<
                !std::is_same<T, U>::value
                && std::is_integral<T>::value && std::is_integral<U>::value
                && std::is_unsigned<T>::value && std::is_signed<U>::value
                && (sizeof(T) >= sizeof(U))
        > * = nullptr>
        constexpr bool in_range(U v)
        {
            static_assert(static_cast<std::make_unsigned_t<U>>(std::numeric_limits<U>::max())
                          <= std::numeric_limits<T>::max(), "should be true");
            return static_cast<std::make_signed_t<T>>(std::numeric_limits<T>::lowest()) <= v;
        }

        template<typename T, typename U, std::enable_if_t<
                !std::is_same<T, U>::value
                && std::is_integral<T>::value && std::is_integral<U>::value
                && std::is_unsigned<T>::value && std::is_signed<U>::value
                && (sizeof(T) < sizeof(U))
        > * = nullptr>
        constexpr bool in_range(U v)
        {
            if (static_cast<std::make_signed_t<T>>(std::numeric_limits<T>::lowest()) <= v) {
                return static_cast<std::make_unsigned_t<U>>(v) <= std::numeric_limits<T>::max();
            }
            return false;
        }

        // convert unsigned integral to signed integral
        template<typename T, typename U, std::enable_if_t<
                !std::is_same<T, U>::value
                && std::is_integral<T>::value && std::is_integral<U>::value
                && std::is_signed<T>::value && std::is_unsigned<U>::value
                && (sizeof(T) > sizeof(U))
        > * = nullptr>
        constexpr bool in_range(U /*v*/)
        {
            static_assert(std::numeric_limits<T>::lowest()
                          <= static_cast<std::make_signed_t<U>>(std::numeric_limits<U>::lowest()), "should be true");
            static_assert(std::numeric_limits<U>::max()
                          <= static_cast<std::make_unsigned_t<T>>(std::numeric_limits<T>::max()), "should be true");
            return true;
        }

        template<typename T, typename U, std::enable_if_t<
                !std::is_same<T, U>::value
                && std::is_integral<T>::value && std::is_integral<U>::value
                && std::is_signed<T>::value && std::is_unsigned<U>::value
                && (sizeof(T) <= sizeof(U))
        > * = nullptr>
        constexpr bool in_range(U v)
        {
            static_assert(std::numeric_limits<T>::lowest()
                          <= static_cast<std::make_signed_t<U>>(std::numeric_limits<U>::lowest()), "should be true");
            return v <= static_cast<std::make_unsigned_t<T>>(std::numeric_limits<T>::max());
        }
    }
}

#endif //RH_UTILS_IN_RANGE_H
