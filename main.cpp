#include <iostream>
#include <vector>
#include "CubePosition.h"
using namespace std;

int main() {
    CubePosition cube;
    cout << "Before Rotation:" << endl;
    cube.print_faces();

    cube.rR();
    cube.rU();
    cube.crR();
    cube.crU();
    cube.crR();
    cube.rF();
    cube.rR();
    cube.rR();
    cube.crU();
    cube.crR();
    cube.crU();
    cube.rR();
    cube.rU();
    cube.crR();
    cube.crF();

    cube.rL();
    cube.rU();
    cube.crL();
    cube.crU();
    cube.crL();
    cube.rB();
    cube.rL();
    cube.rL();
    cube.crU();
    cube.crL();
    cube.crU();
    cube.rL();
    cube.rU();
    cube.crL();
    cube.crB();

    cube.crR();
    cube.rU();
    cube.rU();
    cube.crR();
    cube.crD();
    cube.rR();
    cube.rU();
    cube.crR();
    cube.rD();
    cube.rR();
    cube.crU();
    cube.crR();
    cube.crD();
    cube.rR();
    cube.rU();
    cube.rU();
    cube.crR();
    cube.rD();
    cube.rR();
    cube.rR();

    cout << "\nAfter Rotation:" << endl;
    for (auto& i : cube.faces) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
