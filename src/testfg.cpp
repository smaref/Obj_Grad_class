#include "obj_grad.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {

    
  // creating affinity matrix M,  and diagonal matrix D.
  //double **M_data = new double *[size];
  //double **D_data = new double *[size];
  //double **add_data = new double *[size];

  //for (int i = 0; i < size; ++i) {
  //  M_data[i] = new double[size];
  //  D_data[i] = new double[size];
  //  add_data[i] = new double[size];
  //}

  //for (int i = 0; i < size; ++i) {
  //  for (int j = 0; j < size; ++j) {
  //    if (i == j) {
  //      D_data[i][j] = i * j;
  //      M_data[i][j] = 0;
  //    } else {
  //      D_data[i][j] = 0;
  //      M_data[i][j] = i + j;
  //    }
  //  }
  //}


  /*
  Matrix<double> *M_mat = new Matrix<double>(size, size, M_data);
  Matrix<double> *D_mat = new Matrix<double>(size, size, D_data);
  Matrix<double> *add_mat = new Matrix<double>(size, size, add_data);
  // creating a vecor
  double *vec_data = new double[size];
  double *res_data = new double[size];
  for (int i = 0; i < size; i++) {
    for (int i = 0; i < size; i++) {
      vec_data[i] = size - i;
    }
  }

    Vector<double> *x_vec = new Vector<double>(size, vec_data);
    Vector<double> *grad_vec = new Vector<double>(size, res_data);

    //  objective function
    std::cout << "objective value: " << std::endl;
    std::cout << objFunc(M_mat, D_mat, x_vec);
    std::cout << std::endl;

  // gradient function
    res_data = gradFunc(M_mat, D_mat, x_vec);
    std::cout << "gradient vector: " << std::endl;
    for (int i = 0; i < size; i++) {
      std::cout << res_data[i] << std::endl;
    }
*/

    return 0;
  }

