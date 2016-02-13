#ifndef MATRIX_OPS_H
#define MATRIX_OPS_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace std;
using namespace boost::numeric::ublas;

template<class T>
bool invert_matrix(const matrix<T>& input, matrix<T>& inverse)
{
   typedef permutation_matrix<std::size_t> pmatrix;

   // create a working copy of the input
   matrix<T> A(input);

   // create a permutation matrix for the LU-factorization
   pmatrix pm(A.size1());

   // perform LU-factorization
   int res = lu_factorize(A, pm);
   if (res != 0)
       return false;

   // create identity matrix of "inverse"
   inverse.assign(identity_matrix<T> (A.size1()));

   // backsubstitute to get the inverse
   lu_substitute(A, pm, inverse);

   return true;
}

#endif // MATRIX_OPS_H
