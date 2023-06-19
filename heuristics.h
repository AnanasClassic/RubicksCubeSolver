#pragma once
#include "CubePosition.h"
#include "queue"

class BaseHeuristic {
 public:
  virtual float heuristic(const CubePosition& pos) = 0;
  virtual ~BaseHeuristic() = default;
};

class WhiteCrossHeuristic : public BaseHeuristic {
 public:
  float heuristic(const CubePosition& pos) override {
    size_t count = 0;
    for (int i = 1; i < 9; i += 2) {
      if (pos.get(color::White)[i] != pos.get(color::White)[pos.get(color::White).size() / 2]) {
        ++count;
      }
    }
    for (auto& i : {color::Blue, color::Green, color::Orange, color::Red}) {
        if (pos.get(i)[7] != pos.get(i)[pos.get(i).size() / 2]) {
          ++count;
        }
    }
    return count;
  }
};

class WhiteFaceHeuristic : public BaseHeuristic {
 public:
  float heuristic(const CubePosition& pos) override {
    size_t count = 0;
    for (int i = 0; i < 9; ++i) {
      if (pos.get(color::White)[i] != pos.get(color::White)[pos.get(color::White).size() / 2]) {
        ++count;
      }
    }
    for (auto& c : {color::Blue, color::Green, color::Orange, color::Red}) {
        for (int i = 6; i < 9; ++i) {
          if (pos.get(c)[i] != pos.get(c)[pos.get(c).size() / 2]) {
            ++count;
          }
        }
    }
    return count / 3.f;
  }
};

  class CellCountHeuristic : public BaseHeuristic {
   public:
    float heuristic(const CubePosition& pos) override {
      size_t count = 0;
      for (int i = 0; i < 6; ++i) {
        for (size_t j = 0; j < pos[i].size(); ++j) {
          if (pos[i][j] != pos[i][pos[i].size() / 2]) {
            ++count;
          }
        }
      }
      return count / 12.f;
    }
  };

class WhiteFaceHeuristicPart1 : public BaseHeuristic {
 public:
  float heuristic(const CubePosition& pos) override {
    int count = 0;
    for (int i = 0; i < 9; ++i) {
      if (pos.get(color::White)[i] != pos.get(color::White)[pos.get(color::White).size() / 2]) {
        ++count;
      }
    }
    return std::max(count - 1, 0);
  }
};
class WhiteFaceHeuristicPart2 : public BaseHeuristic {
 public:
  float heuristic(const CubePosition& pos) override {
    size_t count = 0;
    for (int i = 0; i < 9; ++i) {
      if (pos.get(color::White)[i] != pos.get(color::White)[pos.get(color::White).size() / 2]) {
        ++count;
      }
    }
    return count / 2.f;
  }
};
