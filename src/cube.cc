// Copyright 2014 Makoto Yano

#include <Eigen/Core>

namespace common3d {

float CubeVolumeFromBothEndVertix(const Eigen::Vector3f &from
                                , const Eigen::Vector3f &to) {
  Eigen::Vector3f v = from - to;
  float volume = v.x() * v.y() * v.z();
  if (volume < 0) volume = -volume;
  return volume;
}

}  // namespace common3d
