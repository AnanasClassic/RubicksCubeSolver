#pragma once
#include "MoveSequence.h"
class MovePack {
  std::vector<std::pair<MoveSequence, float>> pack;
 public:
  MovePack() {}
  MovePack(std::vector<std::pair<MoveSequence, float>>& seq) : pack(seq) {}
  auto end() { return pack.end(); }
  MovePack& operator+=(const MoveSequence& other) {
    pack.push_back({other, std::max(other.sequence.size(), 3ul)});
  }
  MovePack& operator+=(const MovePack& other) {
    pack.insert(pack.end(), other.pack.begin(), other.pack.end());
  }
  static const MovePack BasicMoves() {
    MovePack pack;
    for (MoveFunction i : {&BasicMove::U, &BasicMove::F, &BasicMove::R, &BasicMove::D, &BasicMove::L, &BasicMove::B, &BasicMove::Ul, &BasicMove::Fl, &BasicMove::Rl, &BasicMove::Dl, &BasicMove::Ll, &BasicMove::Bl}) {
      pack += MoveSequence(std::vector<MoveFunction>{i});
    }
    return pack;
  }
  auto& operator[](size_t i) { return pack[i]; }
  const auto& operator[](size_t i) const { return pack[i]; }
 public:
  auto begin() { return pack.begin(); }
};
