#ifndef ROCKET_H
#define ROCKET_H

#include "engine.hpp"

class Rocket {
private:
  Engine* e;
public:
  virtual double sum_forces() = 0;
  virtual ~Rocket() {}
};

#endif
