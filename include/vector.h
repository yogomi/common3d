// Copyright 2014 Makoto Yano
//
// EigenのVector3fの派生させる場合はここに記述する

#ifndef COMMON3D_INCLUDE_VECTOR_H_  // NOLINT
#define COMMON3D_INCLUDE_VECTOR_H_  // NOLINT

#include <Eigen/Core>

namespace common3d {

// ファイルへ入出力用の最小ベクトル単位
struct MinimumElementVector {
  float x, y, z;
};

// 比較演算子を使えるようにしてstdのmapへキーとして渡せるようにしたVector3f
class ComparableVector3f : public Eigen::Vector3f {
 public:
  ComparableVector3f() {}
  ~ComparableVector3f() {}

  ComparableVector3f(const float x, const float y, const float z)
    : Eigen::Vector3f(x, y, z) {}
  ComparableVector3f(const ComparableVector3f& address)
    : Eigen::Vector3f(address) {}
  explicit ComparableVector3f(const Eigen::Vector3f& vector)
    : Eigen::Vector3f(vector) {}
  ComparableVector3f& operator=(const ComparableVector3f& vector) {
    Eigen::Vector3f::operator=(vector);
    return *this;
  }

  bool operator<(const ComparableVector3f &v) const {
    float left = this->squaredNorm();
    float right = v.squaredNorm();
    if (left == right) {
      if (this->x() != v.x()) {
        return this->x() - v.x();
      } else if (this->y() != v.y()) {
        return this->y() - v.y();
      } else if (this->z() != v.z()) {
        return this->z() - v.z();
      }
    }
    return left < right;
  }
};
}  // namespace common3d

#endif  // COMMON3D_INCLUDE_VECTOR_H_  // NOLINT
