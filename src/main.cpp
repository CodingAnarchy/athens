#include <iostream>
#include <sstream>
#include <thread>
#include <vector>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
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

    using namespace boost::numeric::ublas;
    matrix<double> m(3, 3);
    for (unsigned i = 0; i < m.size1(); i++) {
      for (unsigned j = 0; j < m.size2(); j++) {
        m(i, j) = 3 * i + j;
      }
    }
    std::cout << m << std::endl;

    return 0;
}
