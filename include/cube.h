// Copyright 2014 Makoto Yano

#ifndef COMMON3D_INCLUDE_CUBE_H_  // NOLINT
#define COMMON3D_INCLUDE_CUBE_H_  // NOLINT

#include <Eigen/Core>

namespace common3d {

float CubeVolumeFromBothEndVertix(const Eigen::Vector3f &from
                                , const Eigen::Vector3f &to);

}  // namespace common3d

#endif  // COMMON3D_INCLUDE_CUBE_H_  // NOLINT
