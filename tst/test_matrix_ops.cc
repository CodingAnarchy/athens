#include "matrix_ops.hpp"
#include "gtest/gtest.h"
#include <boost/progress.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <eigen3/Eigen/Dense>
using namespace boost;

TEST(MatrixOps, InvertPerf) {
    matrix<float> m(4, 4);
    m(0,0) = 1; m(0,1) = 2104; m(0,2) = 5; m(0,3) = 1;
    m(1,0) = 1; m(1,1) = 1416; m(1,2) = 3; m(1,3) = 2;
    m(2,0) = 1; m(2,1) = 1534; m(2,2) = 3; m(2,3) = 2;
    m(3,0) = 1; m(3,1) = 852; m(3,2) = 2; m(3,3) = 1;

	matrix<float> Z(4, 4);
    progress_timer timer;

    for(unsigned i = 0; i < 100000; i++) {
        invert_matrix(m, Z);
    }

    cout << "Z = " << endl << Z << endl;
}

TEST(MatrixOps, EigenInvertPerf) {
    using namespace Eigen;

    Matrix4f A, A_prime;
    A << 1, 2104, 5, 1,
         1, 1416, 3, 2,
         1, 1534, 3, 2,
         1, 852, 2, 1;

    cout << "A = " << endl << A << endl;

    progress_timer timer;
    for(unsigned i = 0; i < 100000; i++) {
        A_prime = A.inverse();
    }

    cout << "A_prime = " << endl << A_prime << endl;

}
