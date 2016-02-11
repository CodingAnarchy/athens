#include <iostream>
#include "gtest/gtest.h"
#include "test_rectangle.cc"
#include "test_vulcan.cc"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
