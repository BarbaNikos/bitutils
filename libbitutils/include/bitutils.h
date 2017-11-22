#pragma once
#include <cinttypes>
#include <cstdint>
#include <iostream>

#ifndef BITUTILS_H_
#define BITUTILS_H_

#if defined(_MSC_VER)

#include <intrin.h>
#define popcnt64(x) __popcnt64(x)
#pragma intrinsic(_BitScanForward)
#pragma intrinsic(_BitScanForward64)

#define tzcnt16(x) __mvc_ctz(x)
#define tzcnt32(x) __mvc_ctz(x)
#define tzcnt64(x) __mvc_ctz_64(x)
#define lzcnt8(x) __lzcnt16(x) - CHAR_BIT
#define lzcnt16(x) __lzcnt16(x)
#define lzcnt32(x) __lzcnt(x)
#define lzcnt64(x) __lzcnt64(x)

inline uint32_t __mvc_ctz(uint32_t value) {
  unsigned long mask;
  _BitScanForward(&mask, value);
  return mask;
}

inline uint64_t __mvc_ctz_64(uint64_t value) {
  unsigned long mask;
  _BitScanForward64(&mask, value);
  return mask;
}
#else  // defined(_MSC_VER)
#define popcnt64(x) __builtin_popcountll(x)
#define tzcnt16(x) __builtin_ctz(x)
#define tzcnt32(x) __builtin_ctz(x)
#define tzcnt64(x) __builtin_ctz(x)
#define lzcnt8(x) __builtin_clz(x) - 24
#define lzcnt16(x) __builtin_clz(x) - 16
#define lzcnt32(x) __builtin_clz(x)
#define lzcnt64(x) __builtin_clzl(x)
#endif  // !defined(_MSC_VER_)

class BitWizard {
 public:
  static uint8_t max_uint8(uint8_t x, uint8_t y) {
    return x ^ ((x ^ y) & -(x < y));
  }
  static uint16_t max_uint16(uint16_t x, uint16_t y) {
    return x ^ ((x ^ y) & -(x < y));
  }
  static uint32_t max_uint32(uint32_t x, uint32_t y) {
    return x ^ ((x ^ y) & -(x < y));
  }
  static uint64_t max_uint64(uint64_t x, uint64_t y) {
    return x ^ ((x ^ y) & -(x < y));
  }

  static uint8_t min_uint8(uint8_t x, uint8_t y) {
    return y ^ ((x ^ y) & -(x < y));
  }
  static uint16_t min_uint16(uint16_t x, uint16_t y) {
    return y ^ ((x ^ y) & -(x < y));
  }
  static uint32_t min_uint32(uint32_t x, uint32_t y) {
    return y ^ ((x ^ y) & -(x < y));
  }
  static uint64_t min_uint64(uint64_t x, uint64_t y) {
    return y ^ ((x ^ y) & -(x < y));
  }

  static uint32_t log_base_2_of_power_of_2_uint(uint32_t value);

  static uint32_t swap_bits_32(uint32_t value);

  static uint16_t isolate_bits_16(size_t offset, size_t length, uint16_t value);
  static uint32_t isolate_bits_32(size_t offset, size_t length, uint32_t value);
  static uint64_t isolate_bits_64(size_t offset, size_t length, uint64_t value);

  static uint16_t lowest_order_bit_index_slow(uint16_t value);
  static uint32_t lowest_order_bit_index_slow(uint32_t value);
  static uint64_t lowest_order_bit_index_slow(uint64_t value);

  static uint8_t highest_order_bit_index_slow(uint8_t value);
  static uint16_t highest_order_bit_index_slow(uint16_t value);
  static uint32_t highest_order_bit_index_slow(uint32_t value);
  static uint64_t highest_order_bit_index_slow(uint64_t value);

  static uint8_t lowest_order_bit_index(uint8_t value);
  static uint16_t lowest_order_bit_index(uint16_t value);
  static uint32_t lowest_order_bit_index(uint32_t value);
  static uint64_t lowest_order_bit_index(uint64_t value);

  static uint8_t highest_order_bit_index(uint8_t value);
  static uint16_t highest_order_bit_index(uint16_t value);
  static uint32_t highest_order_bit_index(uint32_t value);
  static uint64_t highest_order_bit_index(uint64_t value);

  static uint16_t lowest_order_bit_index_arch(uint16_t value);
  static uint32_t lowest_order_bit_index_arch(uint32_t value);
  static uint64_t lowest_order_bit_index_arch(uint64_t value);

  static uint8_t highest_order_bit_index_arch(uint8_t value);
  static uint16_t highest_order_bit_index_arch(uint16_t value);
  static uint32_t highest_order_bit_index_arch(uint32_t value);
  static uint64_t highest_order_bit_index_arch(uint64_t value);
};
#endif  // !BITUTILS_H_
