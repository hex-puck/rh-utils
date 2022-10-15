#include <rh-utils/meta.h>
#include <type_traits>

using std::is_same;
using namespace rh_utils::meta;

static_assert(is_same<void, type_at_t<0, void>>::value, "");
static_assert(is_same<void, type_at_t<0, void, int, double>>::value, "");
static_assert(is_same<int, type_at_t<1, void, int, double>>::value, "");
static_assert(is_same<double, type_at_t<2, void, int, double>>::value, "");
static_assert(
    is_same<char, type_at_t<0, char, unsigned char, signed char>>::value, "");
static_assert(is_same<unsigned char,
                      type_at_t<1, char, unsigned char, signed char>>::value,
              "");
static_assert(
    is_same<signed char, type_at_t<2, char, unsigned char, signed char>>::value,
    "");
