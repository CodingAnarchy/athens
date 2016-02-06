#include <iostream>
#include <sstream>
#include <thread>
#include <vector>
using namespace std;

#include "rectangle.h"

void print_hello(int id){
  Rectangle rect = Rectangle(id, id * 2);
  fprintf(stdout, "Thread %d made a rectangle with area %d.\n", id, rect.area());
}

int main() {
    vector<thread> threads(5);
    for (unsigned int i=0; i < threads.size(); i++) {
      threads.at(i) = thread(print_hello, i + 1);
    }

    for (unsigned int i=0; i < threads.size(); i++) {
      threads.at(i).join();
    }

    return 0;
}
