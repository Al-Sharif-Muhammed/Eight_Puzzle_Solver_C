//
// Created by Al-Sh on 10/24/2023.
//

#ifndef EIGHT_PUZZLE_SOLVER_ASTARMAN_H
#define EIGHT_PUZZLE_SOLVER_ASTARMAN_H
#include <vector>
#include <queue>
#include <utility>
#include <stdexcept>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
#include <algorithm>
#include "../Headers/State.h"
#include "../Headers/Search.h"

class AStarMan {
public:
    std::vector<std::vector<int>> path;
    size_t costOfPath;
    size_t nodesExpanded;
    size_t maxDepthSearch;
    size_t runningTime;
    void search();
    explicit AStarMan(const std::vector<int>& grid);
private:
    unsigned int start;
    const unsigned int GOAL{0x76543210};
    std::unordered_set<unsigned int> explored;
    std::unordered_map<unsigned int, std::pair<unsigned int, size_t>> parentMap;
    std::priority_queue<std::pair<unsigned int, std::pair<size_t, size_t>>> frontier;
    bool aStar();
    size_t heuristic(unsigned int state);
};


#endif //EIGHT_PUZZLE_SOLVER_ASTARMAN_H
