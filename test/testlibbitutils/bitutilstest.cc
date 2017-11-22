#include "bitutils.h"
#include "gtest/gtest.h"

TEST(MaxUnsignedInteger, Zero) {
  EXPECT_EQ(1, BitWizard::max_uint8(1, 0));
  EXPECT_EQ(1, BitWizard::max_uint16(1, 0));
  EXPECT_EQ(1, BitWizard::max_uint32(1, 0));
  EXPECT_EQ(1, BitWizard::max_uint64(1, 0));
}

TEST(MaxUnsignedInteger, Negative) {
  EXPECT_NE(1, BitWizard::max_uint8(1, -123));
  EXPECT_NE(1, BitWizard::max_uint16(1, -123));
  EXPECT_NE(1, BitWizard::max_uint32(1, -123));
  EXPECT_NE(1, BitWizard::max_uint64(1, -123));
}

TEST(MinUnsignedInteger, Zero) {
  EXPECT_EQ(0, BitWizard::min_uint8(1, 0));
  EXPECT_EQ(0, BitWizard::min_uint16(1, 0));
  EXPECT_EQ(0, BitWizard::min_uint32(1, 0));
  EXPECT_EQ(0, BitWizard::min_uint64(1, 0));
}

TEST(MinUnsignedInteger, Negative) {
  EXPECT_EQ(1, BitWizard::min_uint8(1, -123));
  EXPECT_EQ(1, BitWizard::min_uint16(1, -123));
  EXPECT_EQ(1, BitWizard::min_uint32(1, -123));
  EXPECT_EQ(1, BitWizard::min_uint64(1, -123));
}

TEST(LogTwoPowerOfTwo, Simple) {
  EXPECT_EQ(0, BitWizard::log_base_2_of_power_of_2_uint(0));
  EXPECT_EQ(1, BitWizard::log_base_2_of_power_of_2_uint(2));
  EXPECT_EQ(5, BitWizard::log_base_2_of_power_of_2_uint(32));
  EXPECT_NE(7, BitWizard::log_base_2_of_power_of_2_uint(127));
}

TEST(SwapBits32, Simple) { EXPECT_EQ(0, BitWizard::swap_bits_32(0)); }

TEST(IsolateBits, Simple) {
  EXPECT_EQ(0x000a, BitWizard::isolate_bits_16(0, 4, 0x00fa));
  EXPECT_EQ(0x0030, BitWizard::isolate_bits_16(4, 4, 0x003f));
  EXPECT_EQ(0x003c, BitWizard::isolate_bits_16(2, 4, 0x007d));
  EXPECT_EQ(0x0000000a, BitWizard::isolate_bits_32(0, 4, 0x0000137a));
  EXPECT_EQ(0x00000070, BitWizard::isolate_bits_32(4, 4, 0x0000137a));
  EXPECT_EQ(0x00000300, BitWizard::isolate_bits_32(8, 4, 0x0000137a));
  EXPECT_EQ(0x0d000000, BitWizard::isolate_bits_32(24, 4, 0x0d00137a));
  EXPECT_EQ(0x05c00000, BitWizard::isolate_bits_32(21, 6, 0x0dc0137a));
}

TEST(LowestOrderBit, Simple) {
  EXPECT_EQ(BitWizard::lowest_order_bit_index_slow((uint16_t)0x0800),
            BitWizard::lowest_order_bit_index((uint16_t)0x0800));
  EXPECT_EQ(BitWizard::lowest_order_bit_index_slow((uint16_t)0x0000),
            BitWizard::lowest_order_bit_index((uint16_t)0x0000));
}

TEST(LowestOrderBit, Intrinsic) {
  EXPECT_EQ(BitWizard::lowest_order_bit_index_slow((uint16_t)0x0800),
            BitWizard::lowest_order_bit_index_arch((uint16_t)0x0800));
  EXPECT_EQ(BitWizard::lowest_order_bit_index_slow((uint16_t)0x0000),
            BitWizard::lowest_order_bit_index_arch((uint16_t)0x0000));
}

TEST(HighestOrderBit, Simple) {
  EXPECT_EQ(BitWizard::highest_order_bit_index_slow((uint16_t)0x0800),
            BitWizard::highest_order_bit_index((uint16_t)0x0800));
  EXPECT_EQ(BitWizard::highest_order_bit_index_slow((uint16_t)0x0000),
            BitWizard::highest_order_bit_index((uint16_t)0x0000));
}

TEST(HighestOrderBit, Intrinsic) {
  EXPECT_EQ(BitWizard::highest_order_bit_index_slow((uint16_t)0x0800),
            BitWizard::highest_order_bit_index_arch((uint16_t)0x0800));
  EXPECT_EQ(BitWizard::highest_order_bit_index_slow((uint16_t)0x0000),
            BitWizard::highest_order_bit_index_arch((uint16_t)0x0000));
}
