#include "gtest/gtest.h"

int main(int argc, char** argv) {
  int exit_code;
  ::testing::InitGoogleTest(&argc, argv);
  exit_code = RUN_ALL_TESTS();
#ifdef _WIN32
  std::cout << "Press ENTER to Continue";
  std::cin.ignore();
  return exit_code;
#else  // _WIN32
  return exit_code;
#endif
}
