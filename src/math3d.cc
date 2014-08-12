// Copyright 2014 Makoto Yano

#include "./vector.h"
#include "./math3d.h"

namespace common3d {

// (UnitBxCx + UnitByCy + UnitBzCz - AxUnitBx - AyUnitBy - AzUnitBz)
// Actually need ( / (UnitBx^2 + UnitBy^2 + UnitBz^2))
// But it should be 1, then it is omitted.
std::function<float(const Vector &)>
  ScaleOfUnitBVectorFromPlanePathAVerticallyB(
                const Vector &va, const Vector &vb) {
  float magnitude = vb.Magnitude();
  float a_dependency = va.x() * vb.x() + va.y() * vb.y() + va.z() * vb.z();

  return [magnitude, a_dependency, &vb](const Vector &vc) -> float {
    return (vb.x() * vc.x() + vb.y() * vc.y() + vb.z() * vc.z() - a_dependency);
  };
}

}  // namespace common3d
