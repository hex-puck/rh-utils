#include <gtest/gtest.h>
#include <type_traits>
#include <rh-utils/meta.h>

TEST(type_sequence, usage)
{
    using std::is_same;
    using namespace rh_utils::meta;

    EXPECT_TRUE((type_sequence<>::size() == 0));
    EXPECT_TRUE((type_sequence<void>::size() == 1));
    EXPECT_TRUE((type_sequence<int>::size() == 1));
    EXPECT_TRUE((type_sequence<void, void>::size() == 2));
    EXPECT_TRUE((type_sequence<void, int>::size() == 2));

    using test_seq_1 = type_sequence<void, int, double>;
    EXPECT_TRUE((is_same<void, typename test_seq_1::type<0>>::value));
    EXPECT_TRUE((is_same<int, typename test_seq_1::type<1>>::value));
    EXPECT_TRUE((is_same<double, typename test_seq_1::type<2>>::value));

    using test_seq_2 = type_sequence<char, unsigned char, signed char>;
    EXPECT_TRUE((is_same<char, typename test_seq_2::type<0>>::value));
    EXPECT_TRUE((is_same<unsigned char, typename test_seq_2::type<1>>::value));
    EXPECT_TRUE((is_same<signed char, typename test_seq_2::type<2>>::value));
}
