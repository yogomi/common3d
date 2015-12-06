// Copyright 2014 Makoto Yano

#ifndef INCLUDE_NEIGHBORHOOD_MAP_H_
#define INCLUDE_NEIGHBORHOOD_MAP_H_

#include <Eigen/Core>

#include <cstdint>
#include <list>
#include <map>

#include "./vector.h"

namespace common3d {

struct BlockId {
  int64_t x, y, z;
  bool operator<(const BlockId &id) const {
    int64_t self_m = x*x + y*y + z*z;
    int64_t m = id.x*id.x + id.y*id.y + id.z*id.z;
    if (self_m == m) {
      if (x != id.x) {
        return x < id.x;
      } else if (y != id.y) {
        return y < id.y;
      } else if (z != id.z) {
        return z < id.z;
      }
    }
    return self_m < m;
  }
  bool operator==(const BlockId &id) const {
    return (id.x == x && id.y == y && id.z == z);
  }
};

typedef std::list<BlockId> BlockIdList;

typedef std::list<ComparableVector3f> _ComparableVector3fList;

typedef std::map<float, _ComparableVector3fList> NeighborhoodMap;

typedef std::map<ComparableVector3f, NeighborhoodMap> VectorTown_;

class BlockGrid {
 public:
  BlockGrid():grid_scale_(1.0f) {}
  explicit BlockGrid(float scale):grid_scale_(scale) {}
  ~BlockGrid() {}
  void AddVector(const Eigen::Vector3f &vector);
  void AddVector(const ComparableVector3f &address);
  NeighborhoodMap GetNeighborsDistanceMap(const Eigen::Vector3f &vector);
  NeighborhoodMap GetNeighborsDistanceMap(const ComparableVector3f &address);
  void RemoveVector(const Eigen::Vector3f &vector);
  void RemoveVector(const ComparableVector3f &address);

 private:
  struct BlockId GetBlockId(const ComparableVector3f &address) const;
  void NoticeNewHouseToTown_(const ComparableVector3f &address
                          , VectorTown_ &town);  // NOLINT
  void RemoveHouseInformationFromTown_(const ComparableVector3f &address
                          , VectorTown_ &town);  // NOLINT
  NeighborhoodMap CreateDistanceMap_(const ComparableVector3f &address);

  float grid_scale_;
  std::map<BlockId, VectorTown_> grid_;
};

}  // namespace common3d

#endif  // INCLUDE_NEIGHBORHOOD_MAP_H_
