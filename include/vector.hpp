#ifndef VECTOR_HPP
#define VECTOR_HPP


// Vector class
template <typename T> class Vector {
  unsigned length; // size of size of the matrix

public:
  Vector(unsigned s, T *v) : length(s), data(v){};
  ~Vector() {
    if (data)
      delete data;
  };
  T *data;

  T dotProduct(Vector<T> *vec);
  void vecAdd(Vector<T> *res);

  unsigned len() { return length; }       // getter
  void SetLen(unsigned l) { length = l; } // setter
  // T Magnitude();
};

#endif /* VECTOR_HPP */

