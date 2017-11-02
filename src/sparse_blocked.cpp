#include "sparse_blocked.hpp"

// read block matrix indices
template <typename T>
void BlockSparseMatrix<T>::readBlockSparseMatIdx(std::string file_name) {

  std::ifstream file_content(file_name.c_str(), std::ios::in);

  if (!file_content) {
    std::cerr << "Could not open file: " << file_name << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string line;
  std::getline(file_content, line);
  std::istringstream row(line);
  row >> num_blocks;

  block_Id.resize(num_blocks);
  int num = 0;
  int i = 0;

  while (std::getline(file_content, line)) {
    std::istringstream ss(line);
    while (ss >> num) {
      block_Id[i].push_back(num);
    }
    if (i < num_blocks)
      ++i;
  }
}

// read block sparse COO matrix
template <typename T>
void BlockSparseMatrix<T>::readBlockSparseMat(std::string file_name) {

  std::ifstream file_content(file_name.c_str(), std::ios::in);

  if (!file_content) {
    std::cerr << "Could not open file: " << file_name << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string line;
  std::getline(file_content, line);
  std::istringstream ss(line);
  ss >> num_blocks;

  value.resize(num_blocks);
  colIdx.resize(num_blocks);
  rowIdx.resize(num_blocks);

  T val;
  int i, col, row;

  while (std::getline(file_content, line)) {
    std::istringstream iss(line);
    if (line.empty()) {
      ++i;
    } else {
      iss >> val;
      iss >> col;
      iss >> row;
      value[i].push_back(val);
      colIdx[i].push_back(col);
      rowIdx[i].push_back(row);
    }
  }
}

template class BlockSparseMatrix<double>;
template class BlockSparseMatrix<float>;

