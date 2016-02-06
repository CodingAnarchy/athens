#include "rectangle.h"
#include "gtest/gtest.h"

TEST(Rectangle, Area) {
  Rectangle r = Rectangle(2, 3);

  EXPECT_EQ(6, r.area());
}

TEST(Rectangle, SetValues) {
  Rectangle r;
  r.set_values(4, 2);

  EXPECT_EQ(8, r.area());
}
