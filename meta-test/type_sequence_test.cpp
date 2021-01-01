#include "type_sequence_test.h"
#include <cstdio>
#include <rh-utils/meta.h>

namespace meta_test {
    void type_sequence_test() noexcept
    {
        std::printf("%s", __func__);

        using namespace rh_utils::meta;
        static_assert(type_sequence<>::size() == 0, "should be true");
        static_assert(type_sequence<void>::size() == 1, "should be true");
        static_assert(type_sequence<int>::size() == 1, "should be true");
        static_assert(type_sequence<void, void>::size() == 2, "should be true");
        static_assert(type_sequence<void, int>::size() == 2, "should be true");
    }
}
