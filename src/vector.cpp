#include "vector.hpp"



// vector-vector dot product
template <typename T> T Vector<T>::dotProduct(Vector<T> *vec) {
  T value = 0;
  for (int i = 0; i < length; i++) {
    value += data[i] * vec->data[i];
  }
  return value;
}

// vector vector subtraction
template <typename T> void Vector<T>::vecAdd(Vector<T> *res) {
  for (int i = 0; i < length; i++)
    data[i] -= res->data[i];
}

