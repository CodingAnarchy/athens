#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
  int width, height;
public:
  Rectangle() = default;
  Rectangle(int w, int h);
  void set_values(int w, int h);
  int area() {return width * height;};
};

#endif
