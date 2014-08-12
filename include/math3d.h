// Copyright 2014 Makoto Yano

#ifndef INCLUDE_MATH3D_H_
#define INCLUDE_MATH3D_H_

#include <functional>

#include "./vector.h"

namespace common3d {

// (UnitBxCx + UnitByCy + UnitBzCz - AxUnitBx - AyUnitBy - AzUnitBz)
//               / (UnitBx^2 + UnitBy^2 + UnitBz^2)
std::function<float(const Vector &)>
              ScaleOfUnitBVectorFromPlanePathAVerticallyB(
                          const Vector &va, const Vector &vb);

}  // namespace common3d

#endif  // INCLUDE_MATH3D_H_
