#include <gtest/gtest.h>
#include <rh-utils/meta.h>
#include <type_traits>

TEST(type_sequence, usage) {
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

  using test_seq_2_1 = type_sequence<char, unsigned char>;
  using test_seq_2_2 = type_sequence<signed char>;
  using splitter = type_sequence_splitter<2, test_seq_2>;
  EXPECT_TRUE((is_same<test_seq_2_1, test_seq_2::rebind<0, 1>::other>::value));
  EXPECT_TRUE((is_same<test_seq_2_2, test_seq_2::rebind<2>::other>::value));
  EXPECT_TRUE((is_same<test_seq_2_1, splitter::front>::value));
  EXPECT_TRUE((is_same<test_seq_2_2, splitter::back>::value));
}
