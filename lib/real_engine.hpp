#ifndef REAL_ENGINE_H
#define REAL_ENGINE_H

#include "engine.hpp"

class RealEngine : public Engine {
public:
  RealEngine() { thrust = 0.0; }
  RealEngine(double th) { thrust = th; }
  double calc_thrust_force() { return thrust * 25; }
  ~RealEngine() {}
};

#endif
