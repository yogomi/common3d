// Copyright 2014 Makoto Yano

#ifndef INCLUDE_POINT_IN_BLOCK_H_
#define INCLUDE_POINT_IN_BLOCK_H_

#include <map>

namespace common3d {

struct BlockId {
  int64_t x, y, z;
  bool operator<(const BlockId &id) const {
    return (id.x < x && id.y < y && id.z < z);
  }
};

}

#endif  // INCLUDE_POINT_IN_BLOCK_H_
