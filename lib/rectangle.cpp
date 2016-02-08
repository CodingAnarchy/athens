#include "rectangle.hpp"

Rectangle::Rectangle(int w, int h) {
  set_values(w, h);
}

void Rectangle::set_values(int w, int h) {
  width = w;
  height = h;
}
