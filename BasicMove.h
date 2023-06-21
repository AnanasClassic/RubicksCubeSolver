#pragma once
#include "CubePosition.h"
namespace BasicMove {

using square = CubePosition::square;
using side = CubePosition::side;

side rotate_face(const side& face);

side counter_rotate_face(const side& face);

std::string U(CubePosition& pos);

std::string F(CubePosition& pos);

std::string R(CubePosition& pos);

std::string B(CubePosition& pos);

std::string L(CubePosition& pos);

std::string D(CubePosition& pos);

std::string Ul(CubePosition& pos);

std::string Fl(CubePosition& pos);

std::string Rl(CubePosition& pos);

std::string Bl(CubePosition& pos);

std::string Ll(CubePosition& pos);

std::string Dl(CubePosition& pos);
} // namespace BasicMove