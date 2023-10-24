//
// Created by Al-Sh on 10/24/2023.
//

#include "../Headers/AStarMan.h"

AStarMan::AStarMan(const std::vector<int> &grid) {
    costOfPath = 0;
    nodesExpanded = 0;
    maxDepthSearch = 0;
    runningTime = 0;
    start = gridToState(grid);
}

bool AStarMan::aStar() {
    size_t h = heuristic(start);
    frontier.push({start, {0 + h, 0}});
    parentMap.insert({start, {start, h}});

    while (!frontier.empty()) {
        unsigned int state = frontier.top().first;
        if (explored.count(state)) {
            continue;
        }
        size_t f = frontier.top().second.first;
        size_t depth = frontier.top().second.second;
        frontier.pop();

        size_t g = f - parentMap.at(state).second;

        if (state == GOAL) {
            return true;
        }
        explored.insert(state);
        std::vector<unsigned int> neighbors(getNeighbors(state));
        for (const unsigned int &neighbor: neighbors) {
            if (!explored.count(neighbor) && !parentMap.count(neighbor)) {
                h = heuristic(neighbor);
                frontier.push({neighbor, {g + 1 + h, depth + 1}});
                parentMap.insert({neighbor, {state, g + 1}});
            } else if (!explored.count(neighbor)) {
                // todo update

            }
        }
    }
    return false;
}

void AStarMan::search() {

}

size_t AStarMan::heuristic(unsigned int state) {
    return 0;
}



