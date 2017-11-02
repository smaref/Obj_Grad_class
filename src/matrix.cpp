#include "matrix.hpp"

// read full matrix

template <typename T> void Matrix<T>::readMatrix(std::string file_name) {

  std::ifstream file_content(file_name.c_str(), std::ios::in);
  if (!file_content) {
    std::cerr << "Could not open file: " << file_name << std::endl;
    exit(EXIT_FAILURE);
  }


  file_content >> row;
  file_content >> col;

  data = new T *[row];
  for (int i = 0; i < row; ++i) {
    data[i] = new T[col];
  }

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      file_content >> data[i][j];
    }
  }

}

// matrix vector product
template <typename T>
void Matrix<T>::mvProduct(Vector<T> *vec, Vector<T> *result) {
  for (int i = 0; i < row; ++i) {
    T val = 0;
    for (int j = 0; j < col; ++j) {
      val += data[i][j] * vec->data[j];
    }
    result->data[i] = val;
  }
}

// matrixi matrix addition
template <typename T> void Matrix<T>::mAddDiag(Matrix<T> *diag) {
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      if (i == j)
        data[i][j] = diag->data[i][j];
      else
        continue;
    }
  }
}

// make diagonal matrix to vector
template <typename T> void Matrix<T>::diagTovec(Vector<T> *vecD) {
  for (int i = 0; i < row; i++)
    vecD->data[i] = data[i][i];
}

// print matrix
template <typename T> void Matrix<T>::printMatrix() {

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      std::cout << data[i][j] << "\t";
    }
  }
  std::cout << std::endl;
}

template class Matrix<double>;
template class Matrix<float>;


