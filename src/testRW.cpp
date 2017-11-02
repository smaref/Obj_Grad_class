#include "blocked_matrix.hpp"
#include "matrix.hpp"
#include "sparse_blocked.hpp"
#include "sparse_matrix.hpp"
#include "vector.hpp"

int main(int argc, char const *argv[]) {
  unsigned size;

  Matrix<double> *aff_mat = new Matrix<double>;
  aff_mat->readMatrix("Input/affinity_org.text");
  // aff_mat->printMatrix();

//  std::cout << aff_mat->row << std::endl;
//  for (int i = 0; i < aff_mat->row; ++i) {
//    for (int j = 0; j < aff_mat->col; ++j) {
//      std::cout << aff_mat->data[i][j] << " ";
//    }
//    std::cout << std::endl;
//  }

  sparseMatrix<double> *aff_sparse = new sparseMatrix<double>;
  aff_sparse->readSparseMatrix("Input/sparse_matrix.text");

//  std::cout << aff_sparse->length << std::endl;
//  for (int i = 0; i < aff_sparse->length; ++i) {
//    std::cout << aff_sparse->value[i] << " ";
//    std::cout << aff_sparse->colIdx[i] << " ";
//    std::cout << aff_sparse->rowIdx[i] << std::endl;
//  }

  BlockMatrix<double> *aff_block = new BlockMatrix<double>;
  aff_block->readBlockMatrix("Input/blocks_vals.text");

//  std::cout << "number of blocks: " << aff_block->num_blocks
//            << "block size:  " << aff_block->length << std::endl;
//  for (int i = 0; i < aff_block->num_blocks; ++i) {
//    for (int j = 0; j < aff_block->length; ++j) {
//      std::cout << aff_block->value[i][j] << " ";
//    }
//    std::cout << std::endl;
//  }

  aff_block->readBlockMatIdx("Input/blocks_idx.text");

//  std::cout << aff_block->num_blocks << std::endl;
//  for (int i = 0; i < aff_block->block_Id.size(); ++i) {
//    for (int j = 0; j < aff_block->block_Id[i].size(); ++j) {
//      std::cout << aff_block->block_Id[i][j] << " ";
//    }
//    std::cout << std::endl;
//  }

  BlockSparseMatrix<double> *aff_sparse_block = new BlockSparseMatrix<double>;

  aff_sparse_block->readBlockSparseMatIdx("Input/blocks_idx.text");

//  std::cout << aff_sparse_block->num_blocks << std::endl;
//  for (int i = 0; i < aff_sparse_block->block_Id.size(); ++i) {
//    for (int j = 0; j < aff_sparse_block->block_Id[i].size(); ++j) {
//      std::cout << aff_sparse_block->block_Id[i][j] << " ";
//    }
//    std::cout << std::endl;
//  }

  aff_sparse_block->readBlockSparseMat("Input/coo_sparse_blocked.text");

//  std::cout << aff_sparse_block->num_blocks << std::endl;
//  for (int i = 0; i < aff_sparse_block->num_blocks; ++i) {
//    for (int j = 0; j < aff_sparse_block->value[i].size(); ++j) {
//      std::cout << aff_sparse_block->value[i][j] << " ";
//      std::cout << aff_sparse_block->colIdx[i][j] << " ";
//      std::cout << aff_sparse_block->rowIdx[i][j] << std::endl;
//    }
//    std::cout << std::endl;
//  }

  return 0;
}
