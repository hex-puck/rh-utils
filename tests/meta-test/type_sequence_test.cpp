#include <rh-utils/meta.h>
#include <type_traits>

using std::is_same;
using namespace rh_utils::meta;

static_assert(type_sequence<>::size() == 0, "");
static_assert(type_sequence<void>::size() == 1, "");
static_assert(type_sequence<int>::size() == 1, "");
static_assert(type_sequence<void, void>::size() == 2, "");
static_assert(type_sequence<void, int>::size() == 2, "");

using test_seq_1 = type_sequence<void, int, double>;
static_assert(is_same<void, typename test_seq_1::type<0>>::value, "");
static_assert(is_same<int, typename test_seq_1::type<1>>::value, "");
static_assert(is_same<double, typename test_seq_1::type<2>>::value, "");

using test_seq_2 = type_sequence<char, unsigned char, signed char>;
static_assert(is_same<char, typename test_seq_2::type<0>>::value, "");
static_assert(is_same<unsigned char, typename test_seq_2::type<1>>::value, "");
static_assert(is_same<signed char, typename test_seq_2::type<2>>::value, "");

using test_seq_2_1 = type_sequence<char, unsigned char>;
using test_seq_2_2 = type_sequence<signed char>;
using splitter = type_sequence_splitter<2, test_seq_2>;
static_assert(is_same<test_seq_2_1, test_seq_2::rebind<0, 1>::other>::value,
              "");
static_assert(is_same<test_seq_2_2, test_seq_2::rebind<2>::other>::value, "");
static_assert(is_same<test_seq_2_1, splitter::front>::value, "");
static_assert(is_same<test_seq_2_2, splitter::back>::value, "");
