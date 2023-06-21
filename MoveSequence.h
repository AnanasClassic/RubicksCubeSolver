#pragma once
#include <utility>
#include <vector>
#include <functional>
#include "BasicMove.h"

using MoveFunction = std::function<std::string(CubePosition&)>;
struct MoveSequence {
  std::vector<MoveFunction> sequence;
  std::string operator()(CubePosition& pos) const {
    std::string str;
    for (auto& f : sequence) {
      str += f(pos) + " ";
    }
    return str;
  }
  MoveSequence& operator+=(const MoveSequence& other) {
    for (auto& f : other.sequence) {
      sequence.push_back(f);
    }
  }
  MoveSequence& operator+=(MoveFunction& other) {
    sequence.push_back(other);
  }
  MoveSequence() {}
  template <typename T = std::vector<MoveFunction>>
  MoveSequence(T&& seq) : sequence(seq) {}
//  MoveSequence(std::initializer_list<MoveFunction> args) : sequence(args) {}
};
