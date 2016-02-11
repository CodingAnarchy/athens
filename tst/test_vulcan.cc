#include "vulcan.hpp"
#include "gtest/gtest.h"

TEST(Vulcan, SumForces) {
  Vulcan v = new Vulcan(1);

  EXPECT_DOUBLE_EQ(10.0, v.sum_forces());
}
