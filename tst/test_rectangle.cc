#include "rectangle.hpp"
#include "gtest/gtest.h"

TEST(Rectangle, DefaultConstructor) {
  Rectangle r;

  EXPECT_EQ(0, r.area());
}

TEST(Rectangle, FullConstructor) {
  Rectangle r = Rectangle(2, 2);

  EXPECT_EQ(4, r.area());
}

TEST(Rectangle, Area) {
  Rectangle r = Rectangle(2, 3);

  EXPECT_EQ(6, r.area());
}

TEST(Rectangle, SetValues) {
  Rectangle r;
  r.set_values(4, 2);

  EXPECT_EQ(8, r.area());
}
