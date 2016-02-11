#ifndef VULCAN_H
#define VULCAN_H

#include "rocket.hpp"

class Vulcan : public Rocket {
public:
  double sum_forces(int thrust) { return thrust * 10.0; }
};

#endif
