#include <chrono>
#include <iostream>
#include <sstream>
#include <vector>
#include "CubePosition.h"
#include "Solver.h"
using namespace std;

int main() {
  float n = 300;
  size_t total_moves = 0;
  auto start = chrono::high_resolution_clock::now();
  for (int i = 0; i < n; ++i) {
    srand(time(0));
    CubePosition cube;
    auto basicPack = MovePack::BasicMoves();
    for (int i = 0; i < 20; ++i) {
      auto rnd = rand() % 12;
      basicPack[rnd].first(cube);
//    std::cout << basicPack[rnd].first(cube) << " ";
    }
    std::string ans;
//  std::cout << std::endl;
//  cout << "Before Rotation:" << endl;
//  cube.print_faces();
    Solver<WhiteCrossHeuristic> cross_solver;
    auto st = cross_solver.solve(cube, basicPack);
//  cout << "After part1:" << endl;
//  st.first.print_faces();
//  std::cout << st.second << endl;
    ans += st.second;
    MovePack whitePack;
    whitePack += MoveSequence(std::vector<MoveFunction>{&BasicMove::U});
    whitePack += MoveSequence(std::vector<MoveFunction>{&BasicMove::Ul});
    whitePack += MoveSequence(std::vector<MoveFunction>{&BasicMove::U, &BasicMove::U});
    whitePack += MoveSequence(std::vector<MoveFunction>{&BasicMove::R, &BasicMove::U, &BasicMove::Rl, &BasicMove::Ul});
    whitePack += MoveSequence(std::vector<MoveFunction>{&BasicMove::B, &BasicMove::U, &BasicMove::Bl, &BasicMove::Ul});
    whitePack += MoveSequence(std::vector<MoveFunction>{&BasicMove::L, &BasicMove::U, &BasicMove::Ll, &BasicMove::Ul});
    whitePack += MoveSequence(std::vector<MoveFunction>{&BasicMove::F, &BasicMove::U, &BasicMove::Fl, &BasicMove::Ul});
    whitePack += MoveSequence(std::vector<MoveFunction>{&BasicMove::F, &BasicMove::Ul, &BasicMove::Fl});
    whitePack += MoveSequence(std::vector<MoveFunction>{&BasicMove::B, &BasicMove::Ul, &BasicMove::Bl});
    whitePack += MoveSequence(std::vector<MoveFunction>{&BasicMove::L, &BasicMove::Ul, &BasicMove::Ll});
    whitePack += MoveSequence(std::vector<MoveFunction>{&BasicMove::B, &BasicMove::Ul, &BasicMove::Bl});
    Solver<WhiteFaceHeuristic> face_solver;
    auto st2 = face_solver.solve(st.first, whitePack);
//  cout << "After part2:" << endl;
//  st2.first.print_faces();
//  std::cout << st2.second << endl;
    ans += st2.second;

    MovePack f2lPack;
    f2lPack += MoveSequence(std::vector<MoveFunction>{&BasicMove::U});
    f2lPack += MoveSequence(std::vector<MoveFunction>{&BasicMove::Ul});
    f2lPack += MoveSequence(std::vector<MoveFunction>{&BasicMove::U, &BasicMove::U});
    f2lPack += MoveSequence(std::vector<MoveFunction>{&BasicMove::R, &BasicMove::Ul, &BasicMove::Rl, &BasicMove::Ul,
                                                      &BasicMove::Fl, &BasicMove::U, &BasicMove::F});
    f2lPack += MoveSequence(std::vector<MoveFunction>{&BasicMove::B, &BasicMove::Ul, &BasicMove::Bl, &BasicMove::Ul,
                                                      &BasicMove::Rl, &BasicMove::U, &BasicMove::R});
    f2lPack += MoveSequence(std::vector<MoveFunction>{&BasicMove::L, &BasicMove::Ul, &BasicMove::Ll, &BasicMove::Ul,
                                                      &BasicMove::Bl, &BasicMove::U, &BasicMove::B});
    f2lPack += MoveSequence(std::vector<MoveFunction>{&BasicMove::F, &BasicMove::Ul, &BasicMove::Fl, &BasicMove::Ul,
                                                      &BasicMove::Ll, &BasicMove::U, &BasicMove::L});
    Solver<FirstThoLayersHeuristic> f2l_solver;
    auto st3 = f2l_solver.solve(st2.first, f2lPack);
//  cout << "After part3:" << endl;
//  st3.first.print_faces();
//  std::cout << st3.second << endl;
    ans += st3.second;
    MovePack YellowFacePack;
    YellowFacePack += MoveSequence(std::vector<MoveFunction>{&BasicMove::U});
    YellowFacePack += MoveSequence(std::vector<MoveFunction>{&BasicMove::Ul});
    YellowFacePack += MoveSequence(std::vector<MoveFunction>{&BasicMove::U, &BasicMove::U});
    YellowFacePack +=
        MoveSequence(std::vector<MoveFunction>{&BasicMove::F, &BasicMove::R, &BasicMove::U, &BasicMove::Rl,
                                               &BasicMove::Ul, &BasicMove::Fl});
    YellowFacePack +=
        MoveSequence(std::vector<MoveFunction>{&BasicMove::R, &BasicMove::U, &BasicMove::Rl, &BasicMove::U,
                                               &BasicMove::R,
                                               &BasicMove::U, &BasicMove::U, &BasicMove::Rl});
    YellowFacePack +=
        MoveSequence(std::vector<MoveFunction>{&BasicMove::L, &BasicMove::Ul, &BasicMove::L, &BasicMove::Ul,
                                               &BasicMove::Ll, &BasicMove::U, &BasicMove::U,
                                               &BasicMove::L});
    Solver<YellowFaceHeuristic> YellowFaceSolver;
    auto st4 = YellowFaceSolver.solve(st3.first, YellowFacePack);
//  cout << "After part4:" << endl;
//  st4.first.print_faces();
//  std::cout << st4.second << endl;
    ans += st4.second;
    MovePack finalPack;
    finalPack += MoveSequence(std::vector<MoveFunction>{&BasicMove::U});
    finalPack += MoveSequence(std::vector<MoveFunction>{&BasicMove::Ul});
    finalPack += MoveSequence(std::vector<MoveFunction>{&BasicMove::U, &BasicMove::U});
    finalPack += MoveSequence(std::vector<MoveFunction>{&BasicMove::Rl, &BasicMove::U, &BasicMove::Ll, &BasicMove::U,
                                                        &BasicMove::U, &BasicMove::R, &BasicMove::Ul, &BasicMove::Rl,
                                                        &BasicMove::U, &BasicMove::U, &BasicMove::R, &BasicMove::L});
    finalPack +=
        MoveSequence(std::vector<MoveFunction>{&BasicMove::R, &BasicMove::Ul, &BasicMove::R, &BasicMove::U,
                                               &BasicMove::R,
                                               &BasicMove::U, &BasicMove::R, &BasicMove::Ul, &BasicMove::Rl,
                                               &BasicMove::Ul, &BasicMove::R, &BasicMove::R});

    Solver<CellCountHeuristic> finalSolver;
    auto st5 = finalSolver.solve(st4.first, finalPack);
//  cout << "After part5:" << endl;
//  st5.first.print_faces();
//  std::cout << st5.second << endl;
//  std::cout << "awesome" << endl;
    ans += st5.second;
//    std::cout << std::endl << ans << std::endl;
    std::stringstream ss(ans);
    int mc = 0;
    for (string s; ss >> s; ++mc) {}
//    std::cout << mc << std::endl;
    total_moves += mc;
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "Averege move count: " << total_moves / n << std::endl;
  std::cout << "Average time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / n << " ms" << std::endl;

}
