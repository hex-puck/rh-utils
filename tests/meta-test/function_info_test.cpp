#include <rh-utils/meta.h>
#include <type_traits>

void usage [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  using func_t = void(int, double);
  using info_t = function_info<func_t>;

  static_assert(is_same<func_t, typename info_t::type>::value, "");
  static_assert(is_same<void, typename info_t::return_type>::value, "");
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value,
                "");
}

void mem_func [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double);
  };
  using func_t = void(int, double);
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value, "");
  static_assert(is_same<void, typename info_t::return_type>::value, "");
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value,
                "");
}

void mem_func_c [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) const;
  };
  using func_t = void(int, double) const;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value, "");
  static_assert(is_same<void, typename info_t::return_type>::value, "");
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value,
                "");
}

void mem_func_v [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) volatile;
  };
  using func_t = void(int, double) volatile;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value, "");
  static_assert(is_same<void, typename info_t::return_type>::value, "");
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value,
                "");
}

void mem_func_cv [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) const volatile;
  };
  using func_t = void(int, double) const volatile;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value, "");
  static_assert(is_same<void, typename info_t::return_type>::value, "");
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value,
                "");
}

void mem_func_lref [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) &;
  };
  using func_t = void(int, double) &;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value, "");
  static_assert(is_same<void, typename info_t::return_type>::value, "");
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value,
                "");
}

void mem_func_c_lref [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) const &;
  };
  using func_t = void(int, double) const &;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value, "");
  static_assert(is_same<void, typename info_t::return_type>::value, "");
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value,
                "");
}

void mem_func_v_lref [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) volatile &;
  };
  using func_t = void(int, double) volatile &;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value, "");
  static_assert(is_same<void, typename info_t::return_type>::value, "");
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value,
                "");
}

void mem_func_cv_lref [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) const volatile &;
  };
  using func_t = void(int, double) const volatile &;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value, "");
  static_assert(is_same<void, typename info_t::return_type>::value, "");
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value,
                "");
}

void mem_func_rref [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) &&;
  };
  using func_t = void(int, double) &&;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value, "");
  static_assert(is_same<void, typename info_t::return_type>::value, "");
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value,
                "");
}

void mem_func_c_rref [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) const &&;
  };
  using func_t = void(int, double) const &&;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value, "");
  static_assert(is_same<void, typename info_t::return_type>::value, "");
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value,
                "");
}

void mem_func_v_rref [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) volatile &&;
  };
  using func_t = void(int, double) volatile &&;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value, "");
  static_assert(is_same<void, typename info_t::return_type>::value, "");
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value,
                "");
}

void mem_func_cv_rref [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) const volatile &&;
  };
  using func_t = void(int, double) const volatile &&;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value, "");
  static_assert(is_same<void, typename info_t::return_type>::value, "");
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value,
                "");
}

#if RH_CXX_STANDARD >= 201703L
void usage_noexcept [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  using func_t = void(int, double) noexcept;
  using info_t = function_info<func_t>;

  static_assert(is_same<func_t, typename info_t::type>::value);
  static_assert(is_same<void, typename info_t::return_type>::value);
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value);
}

void mem_func_noexcept [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) noexcept;
  };
  using func_t = void(int, double) noexcept;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value);
  static_assert(is_same<void, typename info_t::return_type>::value);
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value);
}

void mem_func_c_noexcept [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) const noexcept;
  };
  using func_t = void(int, double) const noexcept;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value);
  static_assert(is_same<void, typename info_t::return_type>::value);
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value);
}

void mem_func_v_noexcept [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) volatile noexcept;
  };
  using func_t = void(int, double) volatile noexcept;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value);
  static_assert(is_same<void, typename info_t::return_type>::value);
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value);
}

void mem_func_cv_noexcept [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) const volatile noexcept;
  };
  using func_t = void(int, double) const volatile noexcept;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value);
  static_assert(is_same<void, typename info_t::return_type>::value);
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value);
}

void mem_func_lref_noexcept [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) &noexcept;
  };
  using func_t = void(int, double) &noexcept;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value);
  static_assert(is_same<void, typename info_t::return_type>::value);
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value);
}

void mem_func_c_lref_noexcept [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) const &noexcept;
  };
  using func_t = void(int, double) const &noexcept;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value);
  static_assert(is_same<void, typename info_t::return_type>::value);
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value);
}

void mem_func_v_lref_noexcept [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) volatile &noexcept;
  };
  using func_t = void(int, double) volatile &noexcept;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value);
  static_assert(is_same<void, typename info_t::return_type>::value);
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value);
}

void mem_func_cv_lref_noexcept [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) const volatile &noexcept;
  };
  using func_t = void(int, double) const volatile &noexcept;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value);
  static_assert(is_same<void, typename info_t::return_type>::value);
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value);
}

void mem_func_rref_noexcept [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) &&noexcept;
  };
  using func_t = void(int, double) &&noexcept;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value);
  static_assert(is_same<void, typename info_t::return_type>::value);
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value);
}

void mem_func_c_rref_noexcept [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) const &&noexcept;
  };
  using func_t = void(int, double) const &&noexcept;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value);
  static_assert(is_same<void, typename info_t::return_type>::value);
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value);
}

void mem_func_v_rref_noexcept [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) volatile &&noexcept;
  };
  using func_t = void(int, double) volatile &&noexcept;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value);
  static_assert(is_same<void, typename info_t::return_type>::value);
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value);
}

void mem_func_cv_rref_noexcept [[maybe_unused]] () {
  using namespace rh_utils::meta;
  using std::is_same;

  struct foo {
    void print(int, double) const volatile &&noexcept;
  };
  using func_t = void(int, double) const volatile &&noexcept;
  using info_t =
      function_info<member_pointer_info<decltype(&foo::print)>::pointed_type>;

  static_assert(std::is_same<func_t, info_t::type>::value);
  static_assert(is_same<void, typename info_t::return_type>::value);
  static_assert(is_same<type_sequence<int, double>,
                        typename info_t::parameter_sequence>::value);
}
#endif
