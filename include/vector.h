// Copyright 2014 Makoto Yano

#ifndef COMMON3D_INCLUDE_VECTOR_H_
#define COMMON3D_INCLUDE_VECTOR_H_

namespace common3d {

template<typename TYPE>class Vector {
 public:
  Vector(): x_(0), y_(0), z_(0) {}
  Vector(const TYPE x, const TYPE y, const TYPE z)
    : x_(x), y_(y), z_(z) {}
  ~Vector() {}

  TYPE x() const {
    return x_;
  }
  TYPE y() const {
    return y_;
  }
  TYPE z() const {
    return z_;
  }
 private:
  TYPE x_, y_, z_;
};

}  // namespace common3d

#endif  // COMMON3D_INCLUDE_VECTOR_H_
