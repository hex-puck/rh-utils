#include <gtest/gtest.h>
#include <rh-utils/meta.h>

RH_HAS_MEMBER_OBJECT(foo)
RH_HAS_MEMBER_FUNCTION(foo)

TEST(has_member, usage)
{
    using namespace rh_utils::meta;

    using class_t1 = struct { int foo; };
    using class_t2 = struct { void foo(); };
    using class_t3 = struct {};
    using class_t4 = struct { void foo(); void foo() const; void foo(int); };

    EXPECT_TRUE(has_member_object_foo<class_t1>::value);
    EXPECT_FALSE(has_member_object_foo<class_t2>::value);
    EXPECT_FALSE(has_member_object_foo<class_t3>::value);
    EXPECT_FALSE(has_member_object_foo<class_t4>::value);

    EXPECT_FALSE(has_member_function_foo<class_t1>::value);
    EXPECT_TRUE(has_member_function_foo<class_t2>::value);
    EXPECT_FALSE(has_member_function_foo<class_t3>::value);
    EXPECT_TRUE(has_member_function_foo<class_t4>::value);
    EXPECT_TRUE(has_member_function_foo<const class_t4>::value);
    EXPECT_TRUE((has_member_function_foo<class_t4, int>::value));
    EXPECT_FALSE((has_member_function_foo<const class_t4, int>::value));
    EXPECT_TRUE((has_member_function_foo<class_t4, double>::value));

    EXPECT_FALSE((has_member_function_foo<class_t2, int>::value));
}
