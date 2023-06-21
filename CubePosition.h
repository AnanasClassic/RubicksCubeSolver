#pragma once

#include <array>
#include <functional>
#include <iostream>
#include <vector>

enum class color {
  Yellow, Blue, Red, Green, Orange, White
};

class CubePosition {
  const size_t Size = 3;

 public:
  using square = char;
  using side = std::array<square, 9>;

 private:
  std::array<side, 6> faces = {
      side{'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'},
      side{'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
      side{'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'},
      side{'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
      side{'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      side{'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}
  };

 public:
  side& get(color c) { return faces[static_cast<size_t>(c)]; }
  const side& get(color c) const { return faces[static_cast<size_t>(c)]; }

  side& operator[](size_t c) { return faces[c]; }
  const side& operator[](size_t c) const { return faces[c]; }

  void print_faces() {
    std::cout << "U: ";
    for (auto& c : get(color::Yellow)) std::cout << c << " ";
    std::cout << std::endl;
    std::cout << "F: ";
    for (auto& c : get(color::Blue)) std::cout << c << " ";
    std::cout << std::endl;
    std::cout << "R: ";
    for (auto& c : get(color::Red)) std::cout << c << " ";
    std::cout << std::endl;
    std::cout << "B: ";
    for (auto& c : get(color::Green)) std::cout << c << " ";
    std::cout << std::endl;
    std::cout << "L: ";
    for (auto& c : get(color::Orange)) std::cout << c << " ";
    std::cout << std::endl;
    std::cout << "D: ";
    for (auto& c : get(color::White)) std::cout << c << " ";
    std::cout << std::endl;
  }

  std::array<side, 6> getView() const { return faces; }

  CubePosition() {}
  CubePosition(const CubePosition&) = default;
  CubePosition& operator=(const CubePosition& other) {
    faces = other.faces;
    return *this;
  }
  bool operator==(const CubePosition& other) const {
    return faces == other.faces;
  }
};

struct CubePositionHash {
  size_t operator()(const CubePosition& pos) const {
    size_t hash = 0;
    for (int i = 0; i < 6; ++i) {
      for (size_t j = 0; j < pos[i].size(); ++j) {
        hash ^= pos[i][j] << (j % 4) * 4;
      }
    }
    return hash;
  }
};