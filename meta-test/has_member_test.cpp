#include <gtest/gtest.h>
#include <rh-utils/meta.h>

RH_HAS_MEMBER(foo)

TEST(has_member, usage)
{
    using namespace rh_utils::meta;

    using class_t1 = struct { int foo; };
    using class_t2 = struct { void foo(); };
    using class_t3 = struct {};

    EXPECT_TRUE(has_member_foo<class_t1>::value);
    EXPECT_FALSE(has_member_foo<class_t2>::value);
    EXPECT_FALSE(has_member_foo<class_t3>::value);
}
