#include <thread>
#include <future>
#include "vulcan.hpp"
using namespace std;

double Vulcan::sum_forces() {
  auto thrust_force = async(&Engine::calc_thrust_force, engine);
  return thrust_force.get() * 10.0;
}
