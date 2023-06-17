#pragma once
#include "CubePosition.h"

class BaseHeuristic {
public:
    virtual size_t heuristic(const CubePosition &pos) = 0;
};

class CellCountHeuristic : public BaseHeuristic {
public:
    size_t heuristic(const CubePosition &pos) override {
        size_t count = 0;
        for (int i = 0; i < 6; ++i) {
            for (size_t j = 0; j < pos[i].size(); ++j) {
                if (pos[i][j] != pos[i][pos[i].size() / 2]) {
                    ++count;
                }
            }
        }
        return count;
    }
};
