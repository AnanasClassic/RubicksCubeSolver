#pragma once

#include <array>
#include <functional>
#include <iostream>
#include <vector>


enum class moveId {
  U,
  Ul,
  F,
  Fl,
  R,
  Rl,
  B,
  Bl,
  L,
  Ll,
  D,
  Dl
};
enum class color {
  Yellow, Blue, Red, Green, Orange, White
};

class CubePosition {
  using square = char;
  using side = std::vector<square>;
  std::vector<side> faces{
      {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'},
      {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
      {'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'},
      {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}
  };

  static void rotateUp(CubePosition& pos);

  static void rotateFront(CubePosition& pos);

  static void rotateRight(CubePosition& pos);

  static void rotateBack(CubePosition& pos);

  static void rotateLeft(CubePosition& pos);

  static void rotateDown(CubePosition& pos);

  static void counterRotateUp(CubePosition& pos);

  static void counterRotateFront(CubePosition& pos);

  static void counterRotateRight(CubePosition& pos);

  static void counterRotateBack(CubePosition& pos);

  static void counterRotateLeft(CubePosition& pos);

  static void counterRotateDown(CubePosition& pos);

  using movePtr = std::function<void(CubePosition&)>;
  static const std::array<movePtr, 12> moves;

 public:
  side& get(color c) { return faces[static_cast<size_t>(c)]; }
  const side& get(color c) const { return faces[static_cast<size_t>(c)]; }

  side& operator[](size_t c) { return faces[c]; }
  const side& operator[](size_t c) const { return faces[c]; }

  static side rotate_face(const side& face) {
    return {face[6], face[3], face[0], face[7], face[4], face[1], face[8],
            face[5], face[2]};
  }

  static side counter_rotate_face(const side& face) {
    return {face[2], face[5], face[8], face[1], face[4], face[7], face[0],
            face[3], face[6]};
  }

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

  std::vector<side> getView() const {
    return faces;
  }

  void move(moveId id);
};