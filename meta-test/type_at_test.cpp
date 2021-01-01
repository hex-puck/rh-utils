#include "type_at_test.h"
#include <cstdio>
#include <type_traits>
#include <rh-utils/meta.h>

void meta_test::type_at_test() noexcept
{
    std::printf("%s", __func__);

    using std::is_same;
    using namespace rh_utils::meta;
    static_assert(is_same<void, type_at_index_t<0, void>>::value, "should be true");
    static_assert(is_same<void, type_at_index_t<0, void, int, double>>::value, "should be true");
    static_assert(is_same<int, type_at_index_t<1, void, int, double>>::value, "should be true");
    static_assert(is_same<double, type_at_index_t<2, void, int, double>>::value, "should be true");
    static_assert(is_same<char, type_at_index_t<0, char, unsigned char, signed char >>::value, "should be true");
    static_assert(is_same<unsigned char, type_at_index_t<1, char, unsigned char, signed char >>::value,
                  "should be true");
    static_assert(is_same<signed char, type_at_index_t<2, char, unsigned char, signed char >>::value, "should be true");
}
