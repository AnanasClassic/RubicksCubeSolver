#pragma once

#include <iostream>
#include <vector>


class CubePosition {
public:
    enum color {
        Yellow, Blue, Red, Green, Orange, White
    };
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


    side rface(const side &face) {
        return {face[6], face[3], face[0], face[7], face[4], face[1], face[8], face[5], face[2]};
    }

    side crface(const side &face) {
        return {face[2], face[5], face[8], face[1], face[4], face[7], face[0], face[3], face[6]};
    }

    void rU() {
        faces[color::Yellow] = rface(faces[color::Yellow]);
        side temp = {faces[color::Red][0], faces[color::Red][1], faces[color::Red][2]};
        for (int i = 0; i < 3; ++i) {
            faces[color::Red][i] = faces[color::Green][i];
            faces[color::Green][i] = faces[color::Orange][i];
            faces[color::Orange][i] = faces[color::Blue][i];
            faces[color::Blue][i] = temp[i];
        }
    }

    void rF() {
        faces[color::Blue] = rface(faces[color::Blue]);
        side temp = {faces[color::Yellow][6], faces[color::Yellow][7], faces[color::Yellow][8]};
        faces[color::Yellow][6] = faces[color::Orange][8];
        faces[color::Yellow][7] = faces[color::Orange][5];
        faces[color::Yellow][8] = faces[color::Orange][2];
        faces[color::Orange][2] = faces[color::White][0];
        faces[color::Orange][5] = faces[color::White][1];
        faces[color::Orange][8] = faces[color::White][2];
        faces[color::White][0] = faces[color::Red][6];
        faces[color::White][1] = faces[color::Red][3];
        faces[color::White][2] = faces[color::Red][0];
        faces[color::Red][0] = temp[0];
        faces[color::Red][3] = temp[1];
        faces[color::Red][6] = temp[2];
    }

    void rR() {
        faces[color::Red] = rface(faces[color::Red]);
        side temp = {faces[color::Yellow][2], faces[color::Yellow][5], faces[color::Yellow][8]};
        faces[color::Yellow][2] = faces[color::Blue][2];
        faces[color::Yellow][5] = faces[color::Blue][5];
        faces[color::Yellow][8] = faces[color::Blue][8];
        faces[color::Blue][2] = faces[color::White][2];
        faces[color::Blue][5] = faces[color::White][5];
        faces[color::Blue][8] = faces[color::White][8];
        faces[color::White][2] = faces[color::Green][6];
        faces[color::White][5] = faces[color::Green][3];
        faces[color::White][8] = faces[color::Green][0];
        faces[color::Green][0] = temp[2];
        faces[color::Green][3] = temp[1];
        faces[color::Green][6] = temp[0];
    }

    void rB() {
        faces[color::Green] = rface(faces[color::Green]);
        side temp = {faces[color::Yellow][0], faces[color::Yellow][1], faces[color::Yellow][2]};
        faces[color::Yellow][0] = faces[color::Red][2];
        faces[color::Yellow][1] = faces[color::Red][5];
        faces[color::Yellow][2] = faces[color::Red][8];
        faces[color::Red][2] = faces[color::White][8];
        faces[color::Red][5] = faces[color::White][7];
        faces[color::Red][8] = faces[color::White][6];
        faces[color::White][6] = faces[color::Orange][0];
        faces[color::White][7] = faces[color::Orange][3];
        faces[color::White][8] = faces[color::Orange][6];
        faces[color::Orange][0] = temp[2];
        faces[color::Orange][3] = temp[1];
        faces[color::Orange][6] = temp[0];
    }

    void rL() {
        faces[color::Orange] = rface(faces[color::Orange]);
        side temp = {faces[color::Yellow][0], faces[color::Yellow][3], faces[color::Yellow][6]};
        faces[color::Yellow][0] = faces[color::Green][8];
        faces[color::Yellow][3] = faces[color::Green][5];
        faces[color::Yellow][6] = faces[color::Green][2];
        faces[color::Green][2] = faces[color::White][6];
        faces[color::Green][5] = faces[color::White][3];
        faces[color::Green][8] = faces[color::White][0];
        faces[color::White][0] = faces[color::Blue][0];
        faces[color::White][3] = faces[color::Blue][3];
        faces[color::White][6] = faces[color::Blue][6];
        faces[color::Blue][0] = temp[0];
        faces[color::Blue][3] = temp[1];
        faces[color::Blue][6] = temp[2];
    }

    void rD() {
        faces[color::White] = rface(faces[color::White]);
        side temp = {faces[color::Red][6], faces[color::Red][7], faces[color::Red][8]};
        for (int i = 0; i < 3; ++i) {
            faces[color::Red][6 + i] = faces[color::Blue][6 + i];
            faces[color::Blue][6 + i] = faces[color::Orange][6 + i];
            faces[color::Orange][6 + i] = faces[color::Green][6 + i];
            faces[color::Green][6 + i] = temp[i];
        }
    }

    void crU() {
        faces[color::Yellow] = crface(faces[color::Yellow]);
        side temp = {faces[color::Red][0], faces[color::Red][1], faces[color::Red][2]};
        for (int i = 0; i < 3; ++i) {
            faces[color::Red][i] = faces[color::Blue][i];
            faces[color::Blue][i] = faces[color::Orange][i];
            faces[color::Orange][i] = faces[color::Green][i];
            faces[color::Green][i] = temp[i];
        }
    }

    void crF() {
        faces[color::Blue] = crface(faces[color::Blue]);
        side temp = {faces[color::Yellow][6], faces[color::Yellow][7], faces[color::Yellow][8]};
        faces[color::Yellow][6] = faces[color::Red][0];
        faces[color::Yellow][7] = faces[color::Red][3];
        faces[color::Yellow][8] = faces[color::Red][6];
        faces[color::Red][0] = faces[color::White][2];
        faces[color::Red][3] = faces[color::White][1];
        faces[color::Red][6] = faces[color::White][0];
        faces[color::White][0] = faces[color::Orange][2];
        faces[color::White][1] = faces[color::Orange][5];
        faces[color::White][2] = faces[color::Orange][8];
        faces[color::Orange][2] = temp[2];
        faces[color::Orange][5] = temp[1];
        faces[color::Orange][8] = temp[0];
    }

    void crR() {
        faces[color::Red] = crface(faces[color::Red]);
        side temp = {faces[color::Yellow][2], faces[color::Yellow][5], faces[color::Yellow][8]};
        faces[color::Yellow][2] = faces[color::Green][6];
        faces[color::Yellow][5] = faces[color::Green][3];
        faces[color::Yellow][8] = faces[color::Green][0];
        faces[color::Green][0] = faces[color::White][8];
        faces[color::Green][3] = faces[color::White][5];
        faces[color::Green][6] = faces[color::White][2];
        faces[color::White][2] = faces[color::Blue][2];
        faces[color::White][5] = faces[color::Blue][5];
        faces[color::White][8] = faces[color::Blue][8];
        faces[color::Blue][2] = temp[0];
        faces[color::Blue][5] = temp[1];
        faces[color::Blue][8] = temp[2];
    }

    void crB() {
        faces[color::Green] = crface(faces[color::Green]);
        side temp = {faces[color::Yellow][0], faces[color::Yellow][1], faces[color::Yellow][2]};
        faces[color::Yellow][0] = faces[color::Orange][6];
        faces[color::Yellow][1] = faces[color::Orange][3];
        faces[color::Yellow][2] = faces[color::Orange][0];
        faces[color::Orange][0] = faces[color::White][6];
        faces[color::Orange][3] = faces[color::White][7];
        faces[color::Orange][6] = faces[color::White][8];
        faces[color::White][6] = faces[color::Red][8];
        faces[color::White][7] = faces[color::Red][5];
        faces[color::White][8] = faces[color::Red][2];
        faces[color::Red][2] = temp[0];
        faces[color::Red][5] = temp[1];
        faces[color::Red][8] = temp[2];
    }

    void crL() {
        faces[color::Orange] = crface(faces[color::Orange]);
        side temp = {faces[color::Yellow][0], faces[color::Yellow][3], faces[color::Yellow][6]};
        faces[color::Yellow][0] = faces[color::Blue][0];
        faces[color::Yellow][3] = faces[color::Blue][3];
        faces[color::Yellow][6] = faces[color::Blue][6];
        faces[color::Blue][0] = faces[color::White][0];
        faces[color::Blue][3] = faces[color::White][3];
        faces[color::Blue][6] = faces[color::White][6];
        faces[color::White][0] = faces[color::Green][8];
        faces[color::White][3] = faces[color::Green][5];
        faces[color::White][6] = faces[color::Green][2];
        faces[color::Green][2] = temp[2];
        faces[color::Green][5] = temp[1];
        faces[color::Green][8] = temp[0];
    }

    void crD() {
        faces[color::White] = crface(faces[color::White]);
        side temp = {faces[color::Red][6], faces[color::Red][7], faces[color::Red][8]};
        for (int i = 0; i < 3; ++i) {
            faces[color::Red][6 + i] = faces[color::Green][6 + i];
            faces[color::Green][6 + i] = faces[color::Orange][6 + i];
            faces[color::Orange][6 + i] = faces[color::Blue][6 + i];
            faces[color::Blue][6 + i] = temp[i];
        }
    }

    void print_faces() {
        std::cout << "U: ";
        for (auto &c: faces[color::Yellow]) std::cout << c << " ";
        std::cout << std::endl;
        std::cout << "F: ";
        for (auto &c: faces[color::Blue]) std::cout << c << " ";
        std::cout << std::endl;
        std::cout << "R: ";
        for (auto &c: faces[color::Red]) std::cout << c << " ";
        std::cout << std::endl;
        std::cout << "B: ";
        for (auto &c: faces[color::Green]) std::cout << c << " ";
        std::cout << std::endl;
        std::cout << "L: ";
        for (auto &c: faces[color::Orange]) std::cout << c << " ";
        std::cout << std::endl;
        std::cout << "D: ";
        for (auto &c: faces[color::White]) std::cout << c << " ";
        std::cout << std::endl;
    }

    std::vector<side> getView() {
        return {faces[color::Yellow], faces[color::Blue], faces[color::Red], faces[color::Green], faces[color::Orange], faces[color::White]};
    }

    const side &getFace(int i) {
        return faces[i];
    }
};