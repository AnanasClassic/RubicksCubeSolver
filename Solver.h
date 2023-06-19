#pragma once
#include "CubePosition.h"
#include "heuristics.h"
#include <unordered_set>
#include <set>
#include <memory>
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
  std::shared_ptr<BaseHeuristic> heuristics = std::make_shared<Heuristic>();
 public:
  std::pair<CubePosition, std::string> solve(CubePosition cube) {
    int iter_count = 0;
    std::unordered_set<CubePosition, CubePositionHash> visited;
    std::priority_queue<state, std::vector<state>, std::greater<state>> unvisited;
    auto moves = cube.getMoves();
    auto dist = heuristics->heuristic(cube);
    unvisited.emplace(cube, dist, 0, "");

    visited.insert(cube);
    while (!unvisited.empty() && iter_count < 100000) {
      auto st = unvisited.top();
      unvisited.pop();
      ++iter_count;
      for (const auto& move : moves) {
        auto copy(st.pos);
        auto move_str = move(copy);
        if (visited.find(copy) != visited.end()) {
          continue;
        }
        auto dist = heuristics->heuristic(copy);
        if (dist == 0) {
          std::cout << std::endl << iter_count << std::endl;
          return {copy, st.last_move + move_str};
        }
        unvisited.emplace(copy, dist, st.depth + 1, st.last_move + move_str + " ");
        visited.insert(st.pos);
      }
    }
    return {cube, "not found\n"};
  }
};