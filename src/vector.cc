// Copyright 2014 Makoto Yano

#include <cmath>

#include "./vector.h"

namespace common3d {

float Vector::DistanceTo(const Vector &v) const {
  struct ExiguousVector other = v.Coordinate();
  return std::sqrt((v_.x - other.x)*(v_.x - other.x) +
                  (v_.y - other.y)*(v_.y - other.y) +
                  (v_.z - other.z)*(v_.z - other.z));
}

float Vector::Magnitude() const {
  return std::sqrt(v_.x*v_.x + v_.y*v_.y + v_.z*v_.z);
}

float Vector::MagnitudeSquared() const {
  return v_.x*v_.x + v_.y*v_.y + v_.z*v_.z;
}

void Vector::Normalize() {
  float denom = MagnitudeSquared();
  if (denom <= 0.0f) {
    v_.x = 0;
    v_.y = 0;
    v_.z = 0;
  } else {
    denom = 1.0f / std::sqrt(denom);
    v_.x = v_.x * denom;
    v_.y = v_.y * denom;
    v_.z = v_.z * denom;
  }
}

Vector Normalize(const Vector &v) {
  float denom = v.MagnitudeSquared();
  if (denom <= 0.0f) {
    return Vector(0, 0, 0);
  }
  denom = 1.0f / std::sqrt(denom);
  return Vector(v.x() * denom, v.y() * denom, v.z() * denom);
}

}  // namespace common3d
