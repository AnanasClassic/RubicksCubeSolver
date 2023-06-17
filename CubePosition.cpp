//
// Created by vlad on 16.06.23.
//

#include "CubePosition.h"

void CubePosition::rotateUp(CubePosition& pos) {
  pos.get(color::Yellow) = rotate_face(pos.get(color::Yellow));
  side temp =
      {pos.get(color::Red)[0], pos.get(color::Red)[1],
       pos.get(color::Red)[2]};
  for (int i = 0; i < 3; ++i) {
    pos.get(color::Red)[i] = pos.get(color::Green)[i];
    pos.get(color::Green)[i] = pos.get(color::Orange)[i];
    pos.get(color::Orange)[i] = pos.get(color::Blue)[i];
    pos.get(color::Blue)[i] = temp[i];
  }
}

void CubePosition::rotateFront(CubePosition& pos) {
  pos.get(color::Blue) = rotate_face(pos.get(color::Blue));
  side temp = {pos.get(color::Yellow)[6], pos.get(color::Yellow)[7],
               pos.get(color::Yellow)[8]};
  pos.get(color::Yellow)[6] = pos.get(color::Orange)[8];
  pos.get(color::Yellow)[7] = pos.get(color::Orange)[5];
  pos.get(color::Yellow)[8] = pos.get(color::Orange)[2];
  pos.get(color::Orange)[2] = pos.get(color::White)[0];
  pos.get(color::Orange)[5] = pos.get(color::White)[1];
  pos.get(color::Orange)[8] = pos.get(color::White)[2];
  pos.get(color::White)[0] = pos.get(color::Red)[6];
  pos.get(color::White)[1] = pos.get(color::Red)[3];
  pos.get(color::White)[2] = pos.get(color::Red)[0];
  pos.get(color::Red)[0] = temp[0];
  pos.get(color::Red)[3] = temp[1];
  pos.get(color::Red)[6] = temp[2];
}

void CubePosition::rotateRight(CubePosition& pos) {
  pos.get(color::Red) = rotate_face(pos.get(color::Red));
  side temp = {pos.get(color::Yellow)[2], pos.get(color::Yellow)[5],
               pos.get(color::Yellow)[8]};
  pos.get(color::Yellow)[2] = pos.get(color::Blue)[2];
  pos.get(color::Yellow)[5] = pos.get(color::Blue)[5];
  pos.get(color::Yellow)[8] = pos.get(color::Blue)[8];
  pos.get(color::Blue)[2] = pos.get(color::White)[2];
  pos.get(color::Blue)[5] = pos.get(color::White)[5];
  pos.get(color::Blue)[8] = pos.get(color::White)[8];
  pos.get(color::White)[2] = pos.get(color::Green)[6];
  pos.get(color::White)[5] = pos.get(color::Green)[3];
  pos.get(color::White)[8] = pos.get(color::Green)[0];
  pos.get(color::Green)[0] = temp[2];
  pos.get(color::Green)[3] = temp[1];
  pos.get(color::Green)[6] = temp[0];
}

void CubePosition::rotateBack(CubePosition& pos) {
  pos.get(color::Green) = rotate_face(pos.get(color::Green));
  side temp = {pos.get(color::Yellow)[0], pos.get(color::Yellow)[1],
               pos.get(color::Yellow)[2]};
  pos.get(color::Yellow)[0] = pos.get(color::Red)[2];
  pos.get(color::Yellow)[1] = pos.get(color::Red)[5];
  pos.get(color::Yellow)[2] = pos.get(color::Red)[8];
  pos.get(color::Red)[2] = pos.get(color::White)[8];
  pos.get(color::Red)[5] = pos.get(color::White)[7];
  pos.get(color::Red)[8] = pos.get(color::White)[6];
  pos.get(color::White)[6] = pos.get(color::Orange)[0];
  pos.get(color::White)[7] = pos.get(color::Orange)[3];
  pos.get(color::White)[8] = pos.get(color::Orange)[6];
  pos.get(color::Orange)[0] = temp[2];
  pos.get(color::Orange)[3] = temp[1];
  pos.get(color::Orange)[6] = temp[0];
}

void CubePosition::rotateLeft(CubePosition& pos) {
  pos.get(color::Orange) = rotate_face(pos.get(color::Orange));
  side temp = {pos.get(color::Yellow)[0], pos.get(color::Yellow)[3],
               pos.get(color::Yellow)[6]};
  pos.get(color::Yellow)[0] = pos.get(color::Green)[8];
  pos.get(color::Yellow)[3] = pos.get(color::Green)[5];
  pos.get(color::Yellow)[6] = pos.get(color::Green)[2];
  pos.get(color::Green)[2] = pos.get(color::White)[6];
  pos.get(color::Green)[5] = pos.get(color::White)[3];
  pos.get(color::Green)[8] = pos.get(color::White)[0];
  pos.get(color::White)[0] = pos.get(color::Blue)[0];
  pos.get(color::White)[3] = pos.get(color::Blue)[3];
  pos.get(color::White)[6] = pos.get(color::Blue)[6];
  pos.get(color::Blue)[0] = temp[0];
  pos.get(color::Blue)[3] = temp[1];
  pos.get(color::Blue)[6] = temp[2];
}

void CubePosition::rotateDown(CubePosition& pos) {
  pos.get(color::White) = rotate_face(pos.get(color::White));
  side temp =
      {pos.get(color::Red)[6], pos.get(color::Red)[7],
       pos.get(color::Red)[8]};
  for (int i = 0; i < 3; ++i) {
    pos.get(color::Red)[6 + i] = pos.get(color::Blue)[6 + i];
    pos.get(color::Blue)[6 + i] = pos.get(color::Orange)[6 + i];
    pos.get(color::Orange)[6 + i] = pos.get(color::Green)[6 + i];
    pos.get(color::Green)[6 + i] = temp[i];
  }
}

void CubePosition::counterRotateUp(CubePosition& pos) {
  pos.get(color::Yellow) = counter_rotate_face(pos.get(color::Yellow));
  side temp =
      {pos.get(color::Red)[0], pos.get(color::Red)[1],
       pos.get(color::Red)[2]};
  for (int i = 0; i < 3; ++i) {
    pos.get(color::Red)[i] = pos.get(color::Blue)[i];
    pos.get(color::Blue)[i] = pos.get(color::Orange)[i];
    pos.get(color::Orange)[i] = pos.get(color::Green)[i];
    pos.get(color::Green)[i] = temp[i];
  }
}

void CubePosition::counterRotateFront(CubePosition& pos) {
  pos.get(color::Blue) = counter_rotate_face(pos.get(color::Blue));
  side temp = {pos.get(color::Yellow)[6], pos.get(color::Yellow)[7],
               pos.get(color::Yellow)[8]};
  pos.get(color::Yellow)[6] = pos.get(color::Red)[0];
  pos.get(color::Yellow)[7] = pos.get(color::Red)[3];
  pos.get(color::Yellow)[8] = pos.get(color::Red)[6];
  pos.get(color::Red)[0] = pos.get(color::White)[2];
  pos.get(color::Red)[3] = pos.get(color::White)[1];
  pos.get(color::Red)[6] = pos.get(color::White)[0];
  pos.get(color::White)[0] = pos.get(color::Orange)[2];
  pos.get(color::White)[1] = pos.get(color::Orange)[5];
  pos.get(color::White)[2] = pos.get(color::Orange)[8];
  pos.get(color::Orange)[2] = temp[2];
  pos.get(color::Orange)[5] = temp[1];
  pos.get(color::Orange)[8] = temp[0];
}

void CubePosition::counterRotateRight(CubePosition& pos) {
  pos.get(color::Red) = counter_rotate_face(pos.get(color::Red));
  side temp = {pos.get(color::Yellow)[2], pos.get(color::Yellow)[5],
               pos.get(color::Yellow)[8]};
  pos.get(color::Yellow)[2] = pos.get(color::Green)[6];
  pos.get(color::Yellow)[5] = pos.get(color::Green)[3];
  pos.get(color::Yellow)[8] = pos.get(color::Green)[0];
  pos.get(color::Green)[0] = pos.get(color::White)[8];
  pos.get(color::Green)[3] = pos.get(color::White)[5];
  pos.get(color::Green)[6] = pos.get(color::White)[2];
  pos.get(color::White)[2] = pos.get(color::Blue)[2];
  pos.get(color::White)[5] = pos.get(color::Blue)[5];
  pos.get(color::White)[8] = pos.get(color::Blue)[8];
  pos.get(color::Blue)[2] = temp[0];
  pos.get(color::Blue)[5] = temp[1];
  pos.get(color::Blue)[8] = temp[2];
}

void CubePosition::counterRotateBack(CubePosition& pos) {
  pos.get(color::Green) = counter_rotate_face(pos.get(color::Green));
  side temp = {pos.get(color::Yellow)[0], pos.get(color::Yellow)[1],
               pos.get(color::Yellow)[2]};
  pos.get(color::Yellow)[0] = pos.get(color::Orange)[6];
  pos.get(color::Yellow)[1] = pos.get(color::Orange)[3];
  pos.get(color::Yellow)[2] = pos.get(color::Orange)[0];
  pos.get(color::Orange)[0] = pos.get(color::White)[6];
  pos.get(color::Orange)[3] = pos.get(color::White)[7];
  pos.get(color::Orange)[6] = pos.get(color::White)[8];
  pos.get(color::White)[6] = pos.get(color::Red)[8];
  pos.get(color::White)[7] = pos.get(color::Red)[5];
  pos.get(color::White)[8] = pos.get(color::Red)[2];
  pos.get(color::Red)[2] = temp[0];
  pos.get(color::Red)[5] = temp[1];
  pos.get(color::Red)[8] = temp[2];
}

void CubePosition::counterRotateLeft(CubePosition& pos) {
  pos.get(color::Orange) = counter_rotate_face(pos.get(color::Orange));
  side temp = {pos.get(color::Yellow)[0], pos.get(color::Yellow)[3],
               pos.get(color::Yellow)[6]};
  pos.get(color::Yellow)[0] = pos.get(color::Blue)[0];
  pos.get(color::Yellow)[3] = pos.get(color::Blue)[3];
  pos.get(color::Yellow)[6] = pos.get(color::Blue)[6];
  pos.get(color::Blue)[0] = pos.get(color::White)[0];
  pos.get(color::Blue)[3] = pos.get(color::White)[3];
  pos.get(color::Blue)[6] = pos.get(color::White)[6];
  pos.get(color::White)[0] = pos.get(color::Green)[8];
  pos.get(color::White)[3] = pos.get(color::Green)[5];
  pos.get(color::White)[6] = pos.get(color::Green)[2];
  pos.get(color::Green)[2] = temp[2];
  pos.get(color::Green)[5] = temp[1];
  pos.get(color::Green)[8] = temp[0];
}

void CubePosition::counterRotateDown(CubePosition& pos) {
  pos.get(color::White) = counter_rotate_face(pos.get(color::White));
  side temp =
      {pos.get(color::Red)[6], pos.get(color::Red)[7],
       pos.get(color::Red)[8]};
  for (int i = 0; i < 3; ++i) {
    pos.get(color::Red)[6 + i] = pos.get(color::Green)[6 + i];
    pos.get(color::Green)[6 + i] = pos.get(color::Orange)[6 + i];
    pos.get(color::Orange)[6 + i] = pos.get(color::Blue)[6 + i];
    pos.get(color::Blue)[6 + i] = temp[i];
  }
}

const std::array<CubePosition::movePtr, 12>
    CubePosition::moves{&CubePosition::rotateUp, &CubePosition::counterRotateUp,
          &CubePosition::rotateFront, &CubePosition::counterRotateFront,
          &CubePosition::rotateRight, &CubePosition::counterRotateRight,
          &CubePosition::rotateBack, &CubePosition::counterRotateBack,
          &CubePosition::rotateLeft, &CubePosition::counterRotateLeft,
          &CubePosition::rotateDown, &CubePosition::counterRotateDown};

void CubePosition::move(moveId id) {
    moves[static_cast<size_t>(id)](*this);
}