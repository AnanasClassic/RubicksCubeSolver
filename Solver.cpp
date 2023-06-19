//
// Created by vlad on 17.06.23.
//

#include "Solver.h"
bool operator<(const state& lhs, const state& rhs) {
  return (lhs.heuristic + lhs.depth < rhs.heuristic + rhs.depth);
}
bool operator>(const state& lhs, const state& rhs) { return rhs < lhs; }
