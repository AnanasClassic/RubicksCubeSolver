#pragma once
#include "CubePosition.h"
#include "heuristics.h"
#include <unordered_set>
#include <set>
#include <memory>
#include "MovePack.h"
struct state {
  CubePosition pos;
  float heuristic;
  float depth;
  std::string last_move;
  state(const CubePosition& pos, float heuristic, float depth, std::string last_move)
      : pos(pos), heuristic(heuristic), depth(depth), last_move(last_move) {}
};
bool operator<(const state& lhs, const state& rhs);
bool operator>(const state& lhs, const state& rhs);
template<typename Heuristic>
class Solver {
  Heuristic heuristic;
 public:
  std::pair<CubePosition, std::string> solve(CubePosition cube, MovePack moves) {
    int iter_count = 0;
    std::unordered_set<CubePosition, CubePositionHash> visited;
    std::priority_queue<state, std::vector<state>, std::greater<>> unvisited;
    auto dist = heuristic.dist(cube);
    unvisited.emplace(cube, dist, 0, "");

    visited.insert(cube);
    while (!unvisited.empty()) {
      auto st = unvisited.top();
      unvisited.pop();
      ++iter_count;
      for (const auto& move : moves) {
        auto copy(st.pos);
        auto move_str = move.first(copy);
        if (visited.find(copy) != visited.end()) {
          continue;
        }
        auto dist = heuristic.dist(copy);
        if (dist == 0) {
//          std::cout << std::endl << iter_count << std::endl;
          return {copy, st.last_move + move_str};
        }
        unvisited.emplace(copy, dist, st.depth + std::min(move.second, 1.f), st.last_move + move_str + " ");
        visited.insert(st.pos);
      }
      if (iter_count > 50000) {
        return {st.pos, "not found\n"};
      }
    }
    return {cube, "not found\n"};
  }
};