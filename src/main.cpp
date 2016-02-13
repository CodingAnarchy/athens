#include <iostream>
#include <sstream>
#include <thread>
#include <vector>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace std;
using namespace boost::numeric::ublas;

#include "vulcan.hpp"
#include "matrix_ops.hpp"

void print_hello(int id){
  Rocket *vulcan = new Vulcan(id);
  fprintf(stdout, "Thread %d made a Vulcan rocket with force %f.\n", id, vulcan->sum_forces());
}

int main() {
  unsigned concurrent_threads_supported = thread::hardware_concurrency();
    std::vector<thread> threads(concurrent_threads_supported);
    for (unsigned int i=0; i < threads.size(); i++) {
      threads.at(i) = thread(print_hello, i + 1);
    }

    for (unsigned int i=0; i < threads.size(); i++) {
      threads.at(i).join();
    }

    matrix<float> m(4, 4);
    m(0,0) = 1; m(0,1) = 2104; m(0,2) = 5; m(0,3) = 1;
    m(1,0) = 1; m(1,1) = 1416; m(1,2) = 3; m(1,3) = 2;
    m(2,0) = 1; m(2,1) = 1534; m(2,2) = 3; m(2,3) = 2;
    m(3,0) = 1; m(3,1) = 852; m(3,2) = 2; m(3,3) = 1;

	matrix<float> Z(4, 4);
	invert_matrix(m, Z);

	cout << "A=" << m << endl << "Z=" << Z << endl;
    cout << "A*Z=" << prod(m, Z) << endl;

	return 0;
}
