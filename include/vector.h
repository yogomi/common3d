// Copyright 2014 Makoto Yano

#ifndef COMMON3D_INCLUDE_VECTOR_H_  // NOLINT
#define COMMON3D_INCLUDE_VECTOR_H_  // NOLINT

#include <list>

namespace common3d {

struct ExiguousVector {
  float x, y, z;
};

class Vector {
 public:
  Vector(): v_({0, 0, 0}) {}
  Vector(const float x, const float y, const float z)
    : v_({x, y, z}) {}
  ~Vector() {}

  float x() const {
    return v_.x;
  }
  float y() const {
    return v_.y;
  }
  float z() const {
    return v_.z;
  }
  struct ExiguousVector Coordinate() const {
    return v_;
  }

  bool operator<(const Vector &v) const {
    return (v.x() < v_.x && v.y() < v_.y && v.z() < v_.z);
  }
  float DistanceTo(const Vector &v) const;
  float Magnitude() const;
  float MagnitudeSquared() const;
  void Normalize();

 private:
  struct ExiguousVector v_;
};

typedef std::list<Vector> VectorList;

Vector Normalize(const Vector &v);

}  // namespace common3d

#endif  // COMMON3D_INCLUDE_VECTOR_H_  // NOLINT
