#include <iostream>
#include <vector>
#include "../Headers/BFS.h"
#include "../Headers/DFS.h"

using namespace std;
void print(vector<vector<int>>& ref) {
    for (auto tt : ref) {
        int inx{};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << tt[inx++] << ' ';
            }
            cout << '\n';
        }
        cout << "======\n";
    }
}
int main() {
    vector<int> grid({1,2,4,5,7,3,8,6,0});
    DFS x = DFS(grid);
    try {
        x.search();
        cout << "Steps:" << '\n';
        print(x.path);
        cout << "cost = " << x.costOfPath << '\n';
        cout << "search depth = " << x.maxDepthSearch << '\n';
        cout << "Running time = " << x.runningTime << " ms\n";
        cout << "Nodes expanded = " << x.nodesExpanded << '\n';
    } catch(exception& e) {
        cout << "No Solution\n";
        cout << "search depth = " << x.maxDepthSearch << '\n';
        cout << "Nodes expanded = " << x.nodesExpanded << '\n';
        cout << "Running time = " << x.runningTime << " ms\n";

    }

    return 0;
}