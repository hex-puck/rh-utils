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
    EXPECT_TRUE(in_range<int>((int) 0));
    EXPECT_TRUE(in_range<int>(nl<int>::max()));

    EXPECT_TRUE(in_range<double>(nl<double>::lowest()));
    EXPECT_TRUE(in_range<double>((double) 0));
    EXPECT_TRUE(in_range<double>(nl<double>::max()));

    EXPECT_TRUE(in_range<short>(nl<short>::lowest()));
    EXPECT_TRUE(in_range<short>((short) 0));
    EXPECT_TRUE(in_range<short>(nl<short>::max()));

    EXPECT_TRUE(in_range<float>(nl<float>::lowest()));
    EXPECT_TRUE(in_range<float>((float) 0));
    EXPECT_TRUE(in_range<float>(nl<float>::max()));
}

TEST(in_range, integral_unsigned_unsigned)
{
    using namespace rh_utils::meta;

    // equal size
    EXPECT_TRUE(in_range<std::uint32_t>(nl<std::uint32_t>::max()));
    EXPECT_TRUE(in_range<std::uint32_t>(nl<std::uint32_t>::lowest()));

    // small -> big
    EXPECT_TRUE(in_range<std::uint32_t>(nl<std::uint8_t>::max()));
    EXPECT_TRUE(in_range<std::uint32_t>(nl<std::uint8_t>::lowest()));

    // big -> small
    EXPECT_FALSE(in_range<std::uint8_t>(nl<std::uint32_t>::max()));
    EXPECT_TRUE(in_range<std::uint8_t>(nl<std::uint32_t>::lowest()));
}

TEST(in_range, integral_signed_signed)
{
    using namespace rh_utils::meta;

    // equal size
    EXPECT_TRUE(in_range<std::int32_t>(nl<std::int32_t>::max()));
    EXPECT_TRUE(in_range<std::int32_t>(nl<std::int32_t>::lowest()));

    // small -> big
    EXPECT_TRUE(in_range<std::int32_t>(nl<std::int8_t>::max()));
    EXPECT_TRUE(in_range<std::int32_t>(nl<std::int8_t>::lowest()));

    // big -> small
    EXPECT_FALSE(in_range<std::int8_t>(nl<std::int32_t>::max()));
    EXPECT_TRUE(in_range<std::int8_t>((std::int32_t) 0));
    EXPECT_FALSE(in_range<std::int8_t>(nl<std::int32_t>::lowest()));
}

TEST(in_range, integral_signed_unsigned)
{
    using namespace rh_utils::meta;

    // equal size
    EXPECT_TRUE(in_range<std::uint32_t>(nl<std::int32_t>::max()));
    EXPECT_FALSE(in_range<std::uint32_t>(nl<std::int32_t>::lowest()));

    // small -> big
    EXPECT_TRUE(in_range<std::uint32_t>(nl<std::int8_t>::max()));
    EXPECT_FALSE(in_range<std::uint32_t>(nl<std::int8_t>::lowest()));

    // big -> small
    EXPECT_FALSE(in_range<std::uint8_t>(nl<std::int32_t>::max()));
    EXPECT_TRUE(in_range<std::uint8_t>((std::int32_t) 0));
    EXPECT_FALSE(in_range<std::uint8_t>(nl<std::int32_t>::lowest()));
}

TEST(in_range, integral_unsigned_signed)
{
    using namespace rh_utils::meta;

    // equal size
    EXPECT_FALSE(in_range<std::int32_t>(nl<std::uint32_t>::max()));
    EXPECT_TRUE(in_range<std::int32_t>(nl<std::uint32_t>::lowest()));

    // small -> big
    EXPECT_TRUE(in_range<std::int32_t>(nl<std::uint8_t>::max()));
    EXPECT_TRUE(in_range<std::int32_t>(nl<std::uint8_t>::lowest()));

    // big -> small
    EXPECT_FALSE(in_range<std::int8_t>(nl<std::uint32_t>::max()));
    EXPECT_TRUE(in_range<std::int8_t>(nl<std::uint32_t>::lowest()));
}
