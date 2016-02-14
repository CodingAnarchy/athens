#include <iostream>
#include <sstream>
#include <thread>
#include <vector>
#include <eigen3/Eigen/Dense>
using namespace std;
using namespace Eigen;

#include "vulcan.hpp"

void print_hello(int id){
  Rocket *vulcan = new Vulcan(id);
  printf("Thread %d made a Vulcan rocket with force %f.\n", id, vulcan->sum_forces());
}

int main() {
    Eigen::initParallel();
    unsigned concurrent_threads_supported = thread::hardware_concurrency();
    std::vector<thread> threads(concurrent_threads_supported);
    for (unsigned int i=0; i < threads.size(); i++) {
      threads.at(i) = thread(print_hello, i + 1);
    }

    for (unsigned int i=0; i < threads.size(); i++) {
      threads.at(i).join();
    }

    Matrix4f A, Z;
    A << 1, 2104, 5, 1,
         1, 1416, 3, 2,
         1, 1534, 3, 2,
         1, 852, 2, 1;
    Z = A.inverse();

	cout << "A=" << endl << A << endl << "Z=" << endl << Z << endl;
    cout << "A*Z=" << endl << A * Z << endl;

	return 0;
}
