#include "blocked_matrix.hpp"

// read block matrixes
template <typename T>
void BlockMatrix<T>::readBlockMatrix(std::string file_name) {

  std::ifstream file_content(file_name.c_str(), std::ios::in);
  if (!file_content) {
    std::cerr << "Could not open file: " << file_name << std::endl;
    exit(EXIT_FAILURE);
  }

  file_content >> num_blocks;
  file_content >> length;

  value = new T *[num_blocks];

  for (int i = 0; i < num_blocks; ++i) {
    value[i] = new T[length];
  }

  for (int i = 0; i < num_blocks; i++) {
    for (int j = 0; j < length; j++) {
      file_content >> value[i][j];
      // std::cout << value[i][j] << " ";
    }
    // std::cout << std::endl;
  }
}

// read block matrix indices
template <typename T>
void BlockMatrix<T>::readBlockMatIdx(std::string file_name) {

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

template class BlockMatrix<double>;
template class BlockMatrix<float>;

