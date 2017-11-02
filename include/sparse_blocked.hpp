#ifndef SPARSE_BLOCKED_HPP
#define SPARSE_BLOCKED_HPP

#include <fstream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <class T> using vec_vec = std::vector<std::vector<T>>;

// Block Sparse Matrix class
template <typename T> class BlockSparseMatrix {
public:
  BlockSparseMatrix(unsigned s, vec_vec<T> v, vec_vec<int> c_Id,
                    vec_vec<int> r_Id, vec_vec<int> bl_id)
      : num_blocks(s), value(v), colIdx(c_Id), rowIdx(r_Id), block_Id(bl_id){};
  BlockSparseMatrix(){};

  unsigned num_blocks; // size of row of the matrix
  vec_vec<T> value;
  vec_vec<int> colIdx;
  vec_vec<int> rowIdx;
  vec_vec<int> block_Id;

  void readBlockSparseMat(std::string file_name);
  void readBlockSparseMatIdx(std::string file_name);
  // void printBlockMatrix();

  ~BlockSparseMatrix(){};
};

#endif /* SPARSE_BLOCKED_HPP */
