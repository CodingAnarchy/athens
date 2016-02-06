#include <iostream>
#include <sstream>
#include <thread>
using namespace std;

#include "rectangle.h"

void print_hello(){
  stringstream id;
  id << this_thread::get_id();
  Rectangle rect = Rectangle(5, 3 * 2);
  fprintf(stdout, "Hello, World! This is thread %s.\n", id.str().c_str());
  fprintf(stdout, "Thread %s made a rectangle with area %d.\n", id.str().c_str(), rect.area());
}

int main() {
    thread t1(print_hello);
    thread t2(print_hello);

    t1.join();
    t2.join();
    return 0;
}
