#include <iostream>
#include "gtest/gtest.h"
#include "test_vulcan.cc"
#include "test_matrix_ops.cc"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
