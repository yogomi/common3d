// Copyright 2014 Makoto Yano

#ifndef COMMON3D_INCLUDE_VECTOR_H_
#define COMMON3D_INCLUDE_VECTOR_H_

namespace common3d {

class Vector {
 public:
  Vector(): x_(0), y_(0), z_(0) {}
  Vector(const float x, const float y, const float z)
    : x_(x), y_(y), z_(z) {}
  ~Vector() {}

  float x() const {
    return x_;
  }
  float y() const {
    return y_;
  }
  float z() const {
    return z_;
  }

  float Magnitude() const;
  float MagnitudeSquared() const;
  void Normalize();
 private:
  float x_, y_, z_;
};

Vector Normalize(const Vector &v);

}  // namespace common3d

#endif  // COMMON3D_INCLUDE_VECTOR_H_
