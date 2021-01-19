#include <gtest/gtest.h>
#include <type_traits>
#include <rh-utils/meta.h>

TEST(type_at, usage)
{
    using std::is_same;
    using namespace rh_utils::meta;

    EXPECT_TRUE((is_same<void, type_at_t<0, void>>::value));
    EXPECT_TRUE((is_same<void, type_at_t<0, void, int, double>>::value));
    EXPECT_TRUE((is_same<int, type_at_t<1, void, int, double>>::value));
    EXPECT_TRUE((is_same<double, type_at_t<2, void, int, double>>::value));
    EXPECT_TRUE((is_same<char, type_at_t<0, char, unsigned char, signed char >>::value));
    EXPECT_TRUE((is_same<unsigned char, type_at_t<1, char, unsigned char, signed char >>::value));
    EXPECT_TRUE((is_same<signed char, type_at_t<2, char, unsigned char, signed char >>::value));
}
