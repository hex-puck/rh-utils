#include <gtest/gtest.h>
#include <rh-utils/meta.h>

namespace {
    template<typename T>
    using nl = std::numeric_limits<T>;
}

TEST(in_range, same_type_int)
{
    using namespace rh_utils::meta;

    EXPECT_TRUE(in_range<int>(nl<int>::lowest()));
    EXPECT_TRUE(in_range<int>((int)0));
    EXPECT_TRUE(in_range<int>(nl<int>::max()));

    EXPECT_TRUE(in_range<double>(nl<double>::lowest()));
    EXPECT_TRUE(in_range<double>((double)0));
    EXPECT_TRUE(in_range<double>(nl<double>::max()));

    EXPECT_TRUE(in_range<short>(nl<short>::lowest()));
    EXPECT_TRUE(in_range<short>((short)0));
    EXPECT_TRUE(in_range<short>(nl<short>::max()));

    EXPECT_TRUE(in_range<float>(nl<float>::lowest()));
    EXPECT_TRUE(in_range<float>((float)0));
    EXPECT_TRUE(in_range<float>(nl<float>::max()));
}
