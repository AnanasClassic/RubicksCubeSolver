#include "BasicMove.h"
namespace BasicMove {

side rotate_face(const side& face) {
  return {face[6], face[3], face[0], face[7], face[4], face[1], face[8],
          face[5], face[2]};
}

side counter_rotate_face(const side& face) {
  return {face[2], face[5], face[8], face[1], face[4], face[7], face[0],
          face[3], face[6]};
}

std::string U(CubePosition& pos) {
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
  return "U";
}

std::string F(CubePosition& pos) {
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
  return "F";
}

std::string R(CubePosition& pos) {
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
  return "R";
}

std::string B(CubePosition& pos) {
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
  return "B";
}

std::string L(CubePosition& pos) {
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
  return "L";
}

std::string D(CubePosition& pos) {
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
  return "D";
}

std::string Ul(CubePosition& pos) {
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
  return "Ul";
}

std::string Fl(CubePosition& pos) {
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
  return "Fl";
}

std::string Rl(CubePosition& pos) {
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
  return "Rl";
}

std::string Bl(CubePosition& pos) {
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
  return "Bl";
}

std::string Ll(CubePosition& pos) {
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
  return "Ll";
}

std::string Dl(CubePosition& pos) {
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
  return "Dl";
}
} // namespace BasicMove