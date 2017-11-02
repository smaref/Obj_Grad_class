#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "vector.hpp" 
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// Matrix class
template <typename T> class Matrix {

public:
  Matrix(unsigned r, unsigned c, T **m) : row(r), col(c), data(m){};
  Matrix(){};

  void readMatrix(std::string file_name);
  void printMatrix();
  void Print();

  void mvProduct(Vector<T> *vec, Vector<T> *result);
  void mAddDiag(Matrix<T> *diag);
  void diagTovec(Vector<T> *vecD);

  ~Matrix() {
    for (int i = 0; i < row; i++)
      delete[] data[i];
    delete[] data;
  };

  T **data{NULL};
  unsigned row; // size of row of the matrix
  unsigned col; // size of column of the matrixi
};



#endif /* MATRIX_HPP */

