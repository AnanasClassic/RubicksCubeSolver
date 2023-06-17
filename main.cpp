#include <iostream>
#include <vector>
#include "CubePosition.h"
using namespace std;

int main() {
    CubePosition cube;
    cout << "Before Rotation:" << endl;
    cube.print_faces();

    for (int i = 0; i < 3; ++i) {
      cube.move(moveId::R);
      cube.move(moveId::U);
      cube.move(moveId::Rl);
      cube.move(moveId::Ul);
    }
    cout << endl;
    cube.print_faces();
    for (int i = 0; i < 3; ++i) {
      cube.move(moveId::R);
      cube.move(moveId::U);
      cube.move(moveId::Rl);
      cube.move(moveId::Ul);
    }
    cout << endl;

    cout << "\nAfter Rotation:" << endl;
    for (int i = 0; i < 6; ++i) {
        for (auto& j : cube[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
