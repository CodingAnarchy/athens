#include <iostream>
#include <sstream>
#include <thread>
#include <vector>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace std;

#include "vulcan.hpp"

void print_hello(int id){
  Rocket *vulcan = new Vulcan();
  fprintf(stdout, "Thread %d made a Vulcan rocket with force %f.\n", id, vulcan->sum_forces(id));
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
