#include "vulcan.hpp"
#include "gtest/gtest.h"

TEST(Vulcan, SumForces) {
  Vulcan v;

  EXPECT_DOUBLE_EQ(10.0, v.sum_forces(1));
  EXPECT_DOUBLE_EQ(20.0, v.sum_forces(2));
}
