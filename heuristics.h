#pragma once
#include "CubePosition.h"
#include "queue"

class BaseHeuristic {
 public:
  virtual float dist(const CubePosition& pos) = 0;
  virtual ~BaseHeuristic() = default;
};

class WhiteCrossHeuristic : public BaseHeuristic {
 public:
  float dist(const CubePosition& pos) override {
    size_t count = 0;
    auto wcolor = pos.get(color::White)[pos.get(color::White).size() / 2];
    for (int i = 1; i < 9; i += 2) {
      if (pos.get(color::White)[i] != wcolor) {
        ++count;
      }
      if (pos.get(color::Yellow)[i] == wcolor) {
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

class WhiteFaceHeuristic : public WhiteCrossHeuristic {
 public:
  float dist(const CubePosition& pos) override {
    size_t count = 0;
    auto wcolor = pos.get(color::White)[pos.get(color::White).size() / 2];
    for (int i = 0; i < 9; ++i) {
      if (pos.get(color::White)[i] != wcolor) {
        ++count;
      }
      if (pos.get(color::Yellow)[i] == wcolor) {
        ++wcolor;
      }
    }
    for (auto& c : {color::Blue, color::Green, color::Orange, color::Red}) {
      for (int i = 6; i < 9; ++i) {
        if (pos.get(c)[i] != pos.get(c)[pos.get(c).size() / 2]) {
          ++count;
        }
        if (pos.get(c)[i] == wcolor) {
          ++count;
        }
      }
    }
    return count / 3.f;
  }
};

class CellCountHeuristic : public WhiteFaceHeuristic {
 public:
  float dist(const CubePosition& pos) override {
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

//class ClearWhiteFaceHeuristic : public BaseHeuristic {
// public:
//  float dist(const CubePosition& pos) override {
//    size_t count = 0;
//    for (int i = 0; i < 9; ++i) {
//      if (pos.get(color::White)[i] != pos.get(color::White)[pos.get(color::White).size() / 2]) {
//        ++count;
//      }
//    }
//    for (auto& c : {color::Blue, color::Green, color::Orange, color::Red}) {
//      for (int i = 6; i < 9; ++i) {
//        if (pos.get(c)[i] != pos.get(c)[pos.get(c).size() / 2]) {
//          ++count;
//        }
//      }
//    }
//    return count / 3.f;
//  }
//};

class FirstThoLayersHeuristic : public BaseHeuristic {
 public:
  float dist(const CubePosition& pos) override {
    size_t count = 0;
    for (int i = 0; i < 9; ++i) {
      if (pos.get(color::White)[i] != pos.get(color::White)[pos.get(color::White).size() / 2]) {
        ++count;
      }
    }
    for (auto& c : {color::Blue, color::Green, color::Orange, color::Red}) {
      for (int i = 3; i < 9; ++i) {
        if (pos.get(c)[i] != pos.get(c)[pos.get(c).size() / 2]) {
          ++count;
        }
      }
    }
    return count / 2.f;
  }
};

class YellowCrossHeuristic : public FirstThoLayersHeuristic {
 public:
  float dist(const CubePosition& pos) override {
    size_t count = 0;
    auto ycolor = pos.get(color::Yellow)[pos.get(color::Yellow).size() / 2];
    for (int i = 1; i < 9; i += 2) {
      if (pos.get(color::Yellow)[i] != ycolor) {
        ++count;
      }
    }
    return count / 2.f + FirstThoLayersHeuristic::dist(pos);
  }
};

class YellowFaceHeuristic : public FirstThoLayersHeuristic {
 public:
  float dist(const CubePosition& pos) override {
    size_t count = 0;
    auto ycolor = pos.get(color::Yellow)[pos.get(color::Yellow).size() / 2];
    for (int i = 0; i < 9; ++i) {
      if (pos.get(color::Yellow)[i] != ycolor) {
        ++count;
      }
    }
    return count / 3.f + FirstThoLayersHeuristic::dist(pos);
  }
};

class YellowRightCrossHeuristic : public YellowFaceHeuristic {
 public:
  float dist(const CubePosition& pos) override {
    size_t count = 0;
    for (auto c : {color::Blue, color::Green, color::Orange, color::Red}) {
      if (pos.get(c)[0] != pos.get(c)[pos.get(c).size() / 2]) {
        ++count;
      }
      if (pos.get(c)[2] != pos.get(c)[pos.get(c).size() / 2]) {
        ++count;
      }
    }
    return count / 2.f + YellowFaceHeuristic::dist(pos);
  }
};