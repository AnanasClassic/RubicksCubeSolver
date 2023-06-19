#include <iostream>
#include <vector>
#include "CubePosition.h"
#include "Solver.h"
using namespace std;

int main() {
  srand(time(0));
  CubePosition cube;
  auto moves = cube.getMoves();
  for (int i = 0; i < 40; ++i) {
    std::cout << moves[rand() % 12](cube) << " ";
  }
  std::cout << std::endl;
  cout << "Before Rotation:" << endl;
  cube.print_faces();
  Solver<WhiteFaceHeuristicPart1> cross_solver;
  auto st = cross_solver.solve(cube);
  cout << "After part1:" << endl;
  st.first.print_faces();
  std::cout << st.second << endl;
  Solver<WhiteFaceHeuristicPart2> face_solver;
  auto st2 = face_solver.solve(st.first);
  cout << "After part2:" << endl;
  st2.first.print_faces();
  std::cout << st2.second << endl;
}
