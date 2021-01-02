#include "type_sequence_test.h"
#include <cstdio>
#include <type_traits>
#include <rh-utils/meta.h>

void meta_test::type_sequence_test() noexcept
{
    std::printf("%s\n", __func__);

    using std::is_same;
    using namespace rh_utils::meta;
    static_assert(type_sequence<>::size() == 0, "should be true");
    static_assert(type_sequence<void>::size() == 1, "should be true");
    static_assert(type_sequence<int>::size() == 1, "should be true");
    static_assert(type_sequence<void, void>::size() == 2, "should be true");
    static_assert(type_sequence<void, int>::size() == 2, "should be true");

    using test_seq_1 = type_sequence<void, int, double>;
    static_assert(is_same<void, typename test_seq_1::type<0>>::value, "should be true");
    static_assert(is_same<int, typename test_seq_1::type<1>>::value, "should be true");
    static_assert(is_same<double, typename test_seq_1::type<2>>::value, "should be true");

    using test_seq_2 = type_sequence<char, unsigned char, signed char>;
    static_assert(is_same<char, typename test_seq_2::type<0>>::value, "should be true");
    static_assert(is_same<unsigned char, typename test_seq_2::type<1>>::value, "should be true");
    static_assert(is_same<signed char, typename test_seq_2::type<2>>::value, "should be true");
}
