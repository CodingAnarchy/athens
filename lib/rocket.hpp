#ifndef ROCKET_H
#define ROCKET_H

#include "engine.hpp"

class Rocket {
protected:
  Engine *engine;
public:
  virtual double sum_forces() = 0;
};

#endif
