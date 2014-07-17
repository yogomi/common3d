// Copyright 2014 Makoto Yano

#include <cmath>

#include "./vector.h"

namespace common3d {

float Vector::Magnitude() const {
  return std::sqrt(x_*x_ + y_*y_ + z_*z_);
}

float Vector::MagnitudeSquared() const {
  return x_*x_ + y_*y_ + z_*z_;
}

void Vector::Normalize() {
  float denom = MagnitudeSquared();
  if (denom <= 0.0f) {
    x_ = 0;
    y_ = 0;
    z_ = 0;
  } else {
    denom = 1.0f / std::sqrt(denom);
    x_ = x_ * denom;
    y_ = y_ * denom;
    z_ = z_ * denom;
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
