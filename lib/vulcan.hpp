#ifndef VULCAN_H
#define VULCAN_H

#include "rocket.hpp"
#include "real_engine.hpp"

class Vulcan : public Rocket {
public:
  Vulcan() { engine = new RealEngine(); }
  Vulcan(int id) { engine = new RealEngine(id); }
  double sum_forces();
};

#endif
