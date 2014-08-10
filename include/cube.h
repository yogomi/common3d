
#ifndef CUBE_H_
#define CUBE_H_

#include "./vector.h"

namespace common3d {
float CubeVolumeFromBothEndVertix(Vector from, Vector to) {
  float x = from.x() - to.x();
  float y = from.y() - to.y();
  float z = from.z() - to.z();
  float volume = x * y * z;
  if (volume < 0) volume = -volume;
  return volume;
}
}

#endif  // CUBE_H_
