// Copyright 2014 Makoto Yano

#ifndef COMMON3D_INCLUDE_VECTOR_H_  // NOLINT
#define COMMON3D_INCLUDE_VECTOR_H_  // NOLINT

#include <list>

namespace common3d {

struct MinimumElementVector {
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
  struct MinimumElementVector Coordinate() const {
    return v_;
  }

  bool operator==(const Vector &v) const {
    return (v_.x == v.x() && v_.y == v.y() && v_.z == v.z());
  }

  bool operator<(const Vector &v) const {
    float left = MagnitudeSquared();
    float right = v.MagnitudeSquared();
    if (left == right) {
      if (v_.x != v.x()) {
        return v_.x - v.x();
      } else if (v_.y != v.y()) {
        return v_.y - v.y();
      } else if (v_.z != v.z()) {
        return v_.z - v.z();
      }
    }
    return left < right;
  }
  float DistanceTo(const Vector &v) const;
  float Magnitude() const;
  float MagnitudeSquared() const;
  void Normalize();

 private:
  struct MinimumElementVector v_;
};

typedef std::list<Vector> VectorList;

Vector Normalize(const Vector &v);

}  // namespace common3d

#endif  // COMMON3D_INCLUDE_VECTOR_H_  // NOLINT
