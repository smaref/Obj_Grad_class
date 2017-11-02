#ifndef SPARSE_MATRIX_HPP
#define SPARSE_MATRIX_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// sparse Matrix class
template <typename T> class sparseMatrix {
public:
  sparseMatrix(unsigned s, T *v, int *cIdx, int *rIdx)
      : length(s), value(v), colIdx(cIdx), rowIdx(rIdx){};
  sparseMatrix(){};

  void readSparseMatrix(std::string file_name);
  void printSparseMatrix();

  ~sparseMatrix() {
    delete[] value;
    delete[] colIdx;
    delete[] rowIdx;
  };

  unsigned length;
  T *value{NULL};
  int *colIdx{NULL};
  int *rowIdx{NULL};
};

#endif /* SPARSE_MATRIX_HPP */

