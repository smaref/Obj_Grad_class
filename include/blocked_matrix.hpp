#ifndef BLOCKED_MATRIX_HPP
#define BLOCKED_MATRIX_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <class T> using vec_vec_t = std::vector<std::vector<T>>; 

// Block Matrix class
template <typename T> class BlockMatrix {
public:
  BlockMatrix(unsigned s, unsigned l, T **m, vec_vec_t<int> bl_id)
      : num_blocks(s), length(l), value(m), block_Id(bl_id){};
  BlockMatrix(){};

  unsigned num_blocks; 
  unsigned length;
  T **value{NULL};
  vec_vec_t<int> block_Id;

  void readBlockMatrix(std::string file_name);
  void readBlockMatIdx(std::string file_name);
  // void printBlockMatrix();

  ~BlockMatrix() {
    for (int i = 0; i < num_blocks; i++) {
      delete[] value[i];
    }
    delete[] value;
  };
};


#endif /* BLOCKED_MATRIX_HPP */

