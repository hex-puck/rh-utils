#include <gtest/gtest.h>
#include <rh-utils/meta.h>
#include <type_traits>

TEST(function_info, usage)
{
    using namespace rh_utils::meta;
    using std::is_same;

    using func_t = void(int, double);
    using info_t = function_info<func_t>;

    EXPECT_TRUE((is_same<func_t, typename info_t::type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double); };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double);
    using bare_func_t = void(int, double);
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_c)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) const; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) const;
    using bare_func_t = void(int, double);
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_v)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) volatile; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) volatile;
    using bare_func_t = void(int, double);
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_cv)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) const volatile; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) const volatile;
    using bare_func_t = void(int, double);
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_lref)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) &; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) &;
    using bare_func_t = void(int, double);
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_c_lref)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) const &; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) const &;
    using bare_func_t = void(int, double);
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_v_lref)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) volatile &; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) volatile &;
    using bare_func_t = void(int, double);
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_cv_lref)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) const volatile &; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) const volatile &;
    using bare_func_t = void(int, double);
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_rref)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) &&; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) &&;
    using bare_func_t = void(int, double);
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_c_rref)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) const &&; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) const &&;
    using bare_func_t = void(int, double);
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_v_rref)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) volatile &&; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) volatile &&;
    using bare_func_t = void(int, double);
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_cv_rref)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) const volatile &&; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) const volatile &&;
    using bare_func_t = void(int, double);
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

#if RH_CXX_STANDARD >= 201703L
TEST(function_info, usage_noexcept)
{
    using namespace rh_utils::meta;
    using std::is_same;

    using func_t = void(int, double) noexcept;
    using info_t = function_info<func_t>;

    EXPECT_TRUE((is_same<func_t, typename info_t::type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_noexcept)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) noexcept; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) noexcept;
    using bare_func_t = void(int, double) noexcept;
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_c_noexcept)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) const noexcept; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) const noexcept;
    using bare_func_t = void(int, double) noexcept;
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_v_noexcept)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) volatile noexcept; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) volatile noexcept;
    using bare_func_t = void(int, double) noexcept;
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_cv_noexcept)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) const volatile noexcept; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) const volatile noexcept;
    using bare_func_t = void(int, double) noexcept;
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_lref_noexcept)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) & noexcept; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) &noexcept;
    using bare_func_t = void(int, double) noexcept;
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_c_lref_noexcept)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) const & noexcept; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) const &noexcept;
    using bare_func_t = void(int, double) noexcept;
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_v_lref_noexcept)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) volatile & noexcept; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) volatile &noexcept;
    using bare_func_t = void(int, double) noexcept;
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_cv_lref_noexcept)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) const volatile & noexcept; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) const volatile &noexcept;
    using bare_func_t = void(int, double) noexcept;
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_rref_noexcept)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) && noexcept; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) &&noexcept;
    using bare_func_t = void(int, double) noexcept;
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_c_rref_noexcept)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) const && noexcept; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) const &&noexcept;
    using bare_func_t = void(int, double) noexcept;
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_v_rref_noexcept)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) volatile && noexcept; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) volatile &&noexcept;
    using bare_func_t = void(int, double) noexcept;
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

TEST(function_info, mem_func_cv_rref_noexcept)
{
    using namespace rh_utils::meta;
    using std::is_same;

    struct foo { void print(int, double) const volatile && noexcept; };
    using class_t = foo;
    using mem_func_t = void (foo::*)(int, double) const volatile &&noexcept;
    using bare_func_t = void(int, double) noexcept;
    using info_t = function_info<decltype(&foo::print)>;

    EXPECT_TRUE((std::is_same<mem_func_t, info_t::type>::value));
    EXPECT_TRUE((std::is_same<class_t, info_t::class_type>::value));
    EXPECT_TRUE((std::is_same<bare_func_t, info_t::bare_type>::value));
    EXPECT_TRUE((is_same<void, typename info_t::return_type>::value));
    EXPECT_TRUE((is_same<type_sequence<int, double>, typename info_t::parameter_sequence>::value));
}

#endif
