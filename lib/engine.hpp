#ifndef ENGINE_H
#define ENGINE_H

class Engine {
private:
  double thrust;
public:
  double get_thrust() { return thrust; }
  virtual double calc_thrust_force() = 0;
  virtual ~Engine() {}
};

#endif
