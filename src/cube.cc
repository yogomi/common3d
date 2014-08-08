// Copyright 2014 Makoto Yano

#include "./vector.h"

namespace common3d {

float CubeVolumeFromBothEndVertix(const Vector &from, const Vector &to) {
  Vector v = from - to;
  float volume = v.x() * v.y() * v.z();
  if (volume < 0) volume = -volume;
  return volume;
}

}  // namespace common3d
