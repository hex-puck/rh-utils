#include <gtest/gtest.h>
#include <rh-utils/meta.h>
#include <type_traits>

TEST(function_info, usage)
{
    using namespace rh_utils::meta;
    using std::is_same;

    using func_type = void(int, double);
    using info_type = function_info<func_type>;

    EXPECT_TRUE((is_same<func_type, typename info_type::type>::value));
    EXPECT_TRUE((is_same<void, typename info_type::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_type::parameter_sequence>::value));
}
