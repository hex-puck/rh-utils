#ifndef RH_UTILS_HAS_MEMBER_H
#define RH_UTILS_HAS_MEMBER_H

#include <rh-utils/meta/void_t.h>
#include <type_traits>
#include <utility>

/**
 *  @brief define a class which can test `<class>.<member>` is or not well-form
 *
 *  Define `rh_utils::meta::has_member_object_##Member` class.
 */
#define RH_HAS_MEMBER_OBJECT(Member)                                           \
  namespace rh_utils {                                                         \
  namespace meta {                                                             \
  template <typename, typename = void>                                         \
  struct has_member_object_##Member : public std::false_type {};               \
                                                                               \
  template <typename C>                                                        \
  struct has_member_object_##Member<                                           \
      C, void_t<decltype(std::declval<C>().Member)>> : public std::true_type { \
  };                                                                           \
  }                                                                            \
  }

/**
 *  @brief define a class which can test `<class>.<member>(Args...)` is or not
 *  well-form
 *
 *  Define `rh_utils::meta::has_member_object_##Member` class.
 */
#define RH_HAS_MEMBER_CALLABLE(Member)                                         \
  namespace rh_utils {                                                         \
  namespace meta {                                                             \
  template <typename C, typename... Args>                                      \
  struct has_member_callable_##Member {                                        \
  private:                                                                     \
    template <typename U, typename... Args0>                                   \
    static std::true_type                                                      \
    test(decltype(std::declval<U>().Member(std::declval<Args0>()...)) *);      \
    template <typename...> static std::false_type test(...);                   \
                                                                               \
  public:                                                                      \
    enum { value = decltype(test<C, Args...>(nullptr))::value };               \
  };                                                                           \
  }                                                                            \
  }

#endif // RH_UTILS_HAS_MEMBER_H
