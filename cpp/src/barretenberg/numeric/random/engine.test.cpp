#include "barretenberg/common/log.hpp"
#include "barretenberg/common/streams.hpp"
#include "engine.hpp"
#include <gtest/gtest.h>

TEST(engine, GetRandomUint64)
{
    auto& engine = numeric::random::get_engine();
    auto a = engine.get_random_uint64();
    auto b = engine.get_random_uint64();
    EXPECT_NE(a, 0U);
    EXPECT_NE(b, 0U);
    EXPECT_NE(a, b);
}

TEST(engine, ResetDebugEngine)
{
    auto& debug_engine = numeric::random::get_debug_engine();

    auto a = debug_engine.get_random_uint64();
    auto b = debug_engine.get_random_uint64();
    EXPECT_NE(a, b);

    debug_engine = numeric::random::get_debug_engine(true);
    auto c = debug_engine.get_random_uint64();
    auto d = debug_engine.get_random_uint64();
    EXPECT_EQ(a, c);
    EXPECT_EQ(b, d);

    auto e = numeric::random::get_engine().get_random_uint64();
    EXPECT_NE(a, e);
}

TEST(engine, GetExpectedDebugValue)
{
    auto& debug_engine = numeric::random::get_debug_engine(true);
    auto a = debug_engine.get_random_uint1024();
    auto expected = from_buffer<uint1024_t>(std::vector<uint8_t>{
        0x69, 0x1f, 0x71, 0xcb, 0xcd, 0xdb, 0x45, 0x74, 0xe5, 0x17, 0x17, 0xa7, 0x29, 0x02, 0x21, 0x4a,
        0x9d, 0xbe, 0xb9, 0x0e, 0x4f, 0x22, 0x5f, 0x0c, 0x6b, 0xa0, 0xcd, 0xcf, 0x77, 0xcf, 0xf1, 0xc1,
        0x03, 0x55, 0xea, 0x48, 0xd3, 0x87, 0x40, 0x68, 0x01, 0x01, 0xb4, 0x3f, 0x6d, 0x17, 0xde, 0x8e,
        0x35, 0x07, 0xf3, 0xd8, 0x20, 0x83, 0x37, 0x19, 0x78, 0x26, 0xe2, 0xe9, 0xea, 0x00, 0x0e, 0xd5,
        0xb0, 0x5d, 0x5a, 0xc5, 0xe7, 0xf7, 0x2b, 0x2c, 0x07, 0x56, 0x70, 0x4b, 0xea, 0x85, 0xbe, 0x38,
        0x35, 0x2b, 0x34, 0xd4, 0x8f, 0x6c, 0x43, 0xc5, 0x93, 0x0f, 0x3d, 0x70, 0xd6, 0xdb, 0x09, 0xa4,
        0x8f, 0x4a, 0xd4, 0x92, 0x4f, 0xbd, 0xc5, 0x22, 0xb0, 0x7b, 0x6c, 0xd0, 0xef, 0x55, 0x08, 0xfd,
        0x66, 0x83, 0x68, 0x48, 0x20, 0xff, 0x40, 0x79, 0x5b, 0x8d, 0x9f, 0x1b, 0xe2, 0x22, 0x0c, 0xba,
    });
    EXPECT_EQ(a, expected);
}
