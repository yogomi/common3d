// Copyright 2014 Makoto Yano

#include <list>
#include <map>
#include <algorithm>

#include "./neighborhood_map.h"

namespace common3d {

BlockIdList NeighborhoodBlockIds(const BlockId &id);

void BlockGrid::AddVector(const Vector &address) {
  struct BlockId id = GetBlockId(address);
  BlockIdList neighbor_ids = NeighborhoodBlockIds(id);
  for_each(neighbor_ids.begin(), neighbor_ids.end()
      , [&](const BlockId &neighbor_town_id) {  // NOLINT
    NoticeNewHouseToTown_(address, grid_[neighbor_town_id]);
  });
  grid_[id][address][0.0f].push_back(address);
}

NeighborhoodMap BlockGrid::GetNeighborsDistanceMap(const Vector &address) {
  struct BlockId id = GetBlockId(address);
  if (grid_[id].find(address) != grid_[id].end()) {
    return grid_[id][address];
  } else {
    return CreateDistanceMap_(address);
  }
}

void BlockGrid::RemoveVector(const Vector &address) {
  struct BlockId id = GetBlockId(address);
  BlockIdList neighbor_ids = NeighborhoodBlockIds(id);
  for_each(neighbor_ids.begin(), neighbor_ids.end()
      , [&](const BlockId &neighbor_town_id) {  // NOLINT
    RemoveHouseInformationFromTown_(address, grid_[neighbor_town_id]);
  });
  grid_[id].erase(address);
}

struct BlockId BlockGrid::GetBlockId(const Vector &address) const {
  BlockId id = {static_cast<int64_t>(address.x() / grid_scale_)
              , static_cast<int64_t>(address.y() / grid_scale_)
              , static_cast<int64_t>(address.z() / grid_scale_)};
  return id;
}

void BlockGrid::NoticeNewHouseToTown_(const Vector &address
                          , VectorTown_ &town) {  // NOLINT
  BlockId home_town = GetBlockId(address);
  for (auto& neighbor_house : town) {
    float distance = neighbor_house.first.DistanceTo(address);
    neighbor_house.second[distance].push_back(address);
    grid_[home_town][address][distance].push_back(neighbor_house.first);
  }
}

void BlockGrid::RemoveHouseInformationFromTown_(const Vector &address
                          , VectorTown_ &town) {  // NOLINT
  for (auto& neighbor_house : town) {
    float distance = neighbor_house.first.DistanceTo(address);
    neighbor_house.second[distance].remove(address);
  }
}

NeighborhoodMap BlockGrid::CreateDistanceMap_(const Vector &address) {
  struct BlockId home_id = GetBlockId(address);
  BlockIdList neighbor_ids = NeighborhoodBlockIds(home_id);
  NeighborhoodMap DistanceMap;

  auto CalculateDistance = [&](const struct BlockId &id) {  // NOLINT
    for (auto& neighbor_house : grid_[id]) {
      float distance = neighbor_house.first.DistanceTo(address);
      DistanceMap[distance].push_back(address);
    }
  };

  for_each(neighbor_ids.begin()
          , neighbor_ids.end()
          , [&CalculateDistance](const struct BlockId &id) {
    CalculateDistance(id);
  });

  return DistanceMap;
}

BlockIdList NeighborhoodBlockIds(const BlockId &id) {
  auto NeighborhoodMax = [](const int64_t i) -> int64_t {
    if (i == INT64_MAX) {
      return INT64_MAX;
    }
    return i + 1;
  };
  auto NeighborhoodMin = [](const int64_t i) -> int64_t {
    if (i == INT64_MIN) {
      return INT64_MIN;
    }
    return i - 1;
  };

  BlockId max = {NeighborhoodMax(id.x)
              , NeighborhoodMax(id.y)
              , NeighborhoodMax(id.z)};
  BlockId min = {NeighborhoodMin(id.x)
              , NeighborhoodMin(id.y)
              , NeighborhoodMin(id.z)};

  BlockIdList ids;
  for (int64_t i = min.x; i <= max.x; ++i) {
    for (int64_t j = min.y; j <= max.y; ++j) {
      for (int64_t k = min.z; k <= max.z; ++k) {
        BlockId neighbor_id = {i, j, k};
        ids.push_back(neighbor_id);
      }
    }
  }
  return ids;
}

}  // namespace common3d
