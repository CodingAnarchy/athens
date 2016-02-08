#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
  int width, height;
public:
  Rectangle(int w = 0, int h = 0);
  void set_values(int w, int h);
  int area() {return width * height;};
};

#endif
