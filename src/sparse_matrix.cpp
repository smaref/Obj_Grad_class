#include "sparse_matrix.hpp"

// read sparse matrix
template <typename T>
void sparseMatrix<T>::readSparseMatrix(std::string file_name) {

  std::ifstream file_content(file_name.c_str(), std::ios::in);

  if (!file_content) {
    std::cerr << "Could not open file: " << file_name << std::endl;
    exit(EXIT_FAILURE);
  }

  file_content >> length;

  value = new T[length];
  colIdx = new int[length];
  rowIdx = new int[length];

  for (int i = 0; i < length; ++i) {
    file_content >> value[i];
    file_content >> colIdx[i];
    file_content >> rowIdx[i];
    // std::cout << value[i] << "  "<< colIdx[i] << " " << rowIdx[i] <<
    // std::endl;
  }
}

template class sparseMatrix<double>;
template class sparseMatrix<float>;

