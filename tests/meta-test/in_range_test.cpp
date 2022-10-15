#include <rh-utils/meta.h>

namespace {
template <typename T> using nl = std::numeric_limits<T>;
}

using namespace rh_utils::meta;

static_assert(in_range<int>(nl<int>::lowest()), "");
static_assert(in_range<int>((int)0), "");
static_assert(in_range<int>(nl<int>::max()), "");

static_assert(in_range<double>(nl<double>::lowest()), "");
static_assert(in_range<double>((double)0), "");
static_assert(in_range<double>(nl<double>::max()), "");

static_assert(in_range<short>(nl<short>::lowest()), "");
static_assert(in_range<short>((short)0), "");
static_assert(in_range<short>(nl<short>::max()), "");

static_assert(in_range<float>(nl<float>::lowest()), "");
static_assert(in_range<float>((float)0), "");
static_assert(in_range<float>(nl<float>::max()), "");

// equal size
static_assert(in_range<std::uint32_t>(nl<std::uint32_t>::max()), "");
static_assert(in_range<std::uint32_t>(nl<std::uint32_t>::lowest()), "");

// small -> big
static_assert(in_range<std::uint32_t>(nl<std::uint8_t>::max()), "");
static_assert(in_range<std::uint32_t>(nl<std::uint8_t>::lowest()), "");

// big -> small
static_assert(!in_range<std::uint8_t>(nl<std::uint32_t>::max()), "");
static_assert(in_range<std::uint8_t>(nl<std::uint32_t>::lowest()), "");

// equal size
static_assert(in_range<std::int32_t>(nl<std::int32_t>::max()), "");
static_assert(in_range<std::int32_t>(nl<std::int32_t>::lowest()), "");

// small -> big
static_assert(in_range<std::int32_t>(nl<std::int8_t>::max()), "");
static_assert(in_range<std::int32_t>(nl<std::int8_t>::lowest()), "");

// big -> small
static_assert(!in_range<std::int8_t>(nl<std::int32_t>::max()), "");
static_assert(in_range<std::int8_t>((std::int32_t)0), "");
static_assert(!in_range<std::int8_t>(nl<std::int32_t>::lowest()), "");

// equal size
static_assert(in_range<std::uint32_t>(nl<std::int32_t>::max()), "");
static_assert(!in_range<std::uint32_t>(nl<std::int32_t>::lowest()), "");

// small -> big
static_assert(in_range<std::uint32_t>(nl<std::int8_t>::max()), "");
static_assert(!in_range<std::uint32_t>(nl<std::int8_t>::lowest()), "");

// big -> small
static_assert(!in_range<std::uint8_t>(nl<std::int32_t>::max()), "");
static_assert(in_range<std::uint8_t>((std::int32_t)0), "");
static_assert(!in_range<std::uint8_t>(nl<std::int32_t>::lowest()), "");

// equal size
static_assert(!in_range<std::int32_t>(nl<std::uint32_t>::max()), "");
static_assert(in_range<std::int32_t>(nl<std::uint32_t>::lowest()), "");

// small -> big
static_assert(in_range<std::int32_t>(nl<std::uint8_t>::max()), "");
static_assert(in_range<std::int32_t>(nl<std::uint8_t>::lowest()), "");

// big -> small
static_assert(!in_range<std::int8_t>(nl<std::uint32_t>::max()), "");
static_assert(in_range<std::int8_t>(nl<std::uint32_t>::lowest()), "");
