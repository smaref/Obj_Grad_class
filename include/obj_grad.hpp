/*
objective function: sigma(i=0:npnq)sigma(j=0:npnq)(M(i,j)-D(i,j))*x(i)x(j) +
1(i)*D(i,j)*x(j)

gradient function:  g(f(x)) = sigma(i=0:npnq)sigma(j=0:npnq)(M(i,j) -
D(i,j))*x(j) + D(i,j)*1(j)

 * np and nq number of features in img1 and img2
* M, affinity matrix with off diagonal entries
* D, matrix with only diagonal values
* x, indicator vector
*/

#ifndef _OBJ_GRAD_HPP_
#define _OBJ_GRAD_HPP_

#include "classes.hpp"
#include <math.h>
#include <vector>

// The objective value
template <class T>
T objFunc(Matrix<T> *affinity_mat_M, Matrix<T> *diagonal_mat_D,
          Vector<T> *indicator_vec_x) {

  int size = indicator_vec_x->len();
  
  double *res_vec1 = new double[size];
  double *res_vec2 = new double[size];
  Vector<double> *result1 = new Vector<double>(size, res_vec1);
  Vector<double> *result2 = new Vector<double>(size, res_vec2);
  
  affinity_mat_M->mAddDiag(diagonal_mat_D);
  affinity_mat_M->mvProduct(indicator_vec_x, result1);

  diagonal_mat_D->diagTovec(result2);

  return result2->dotProduct(indicator_vec_x) - result1->dotProduct(indicator_vec_x);
  
}

// The gradient vector
template <class T>
T *gradFunc(Matrix<T> *affinity_mat_M, Matrix<T> *diagonal_mat_D,
            Vector<T> *indicator_vec_x) {

  int size = indicator_vec_x->len();
  
  double *res_vec1 = new double[size];
  double *res_vec2 = new double[size];
  Vector<double> *result1 = new Vector<double>(size, res_vec1);
  Vector<double> *result2 = new Vector<double>(size, res_vec2);
  
  affinity_mat_M->mAddDiag(diagonal_mat_D);
  affinity_mat_M->mvProduct(indicator_vec_x, result1);
  diagonal_mat_D->diagTovec(result2);

  result2->vecAdd(result1);
  
  return res_vec2; 
    
}

#endif /* include "structs.hpp" _OBJ_GRAD_HPP_ */

