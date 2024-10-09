#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define N 4

int findMinEdgeCost(const vector<vector<int>>& dist, int i) {
    int minCost = INT_MAX;
    for (int j = 0; j < N; j++) {
        if (i != j) {
            minCost = min(minCost, dist[i][j]);
        }
    }
    return minCost;
}

int findSecondMinEdgeCost(const vector<vector<int>>& dist, int i) {
    int firstMin = INT_MAX, secondMin = INT_MAX;
    for (int j = 0; j < N; j++) {
        if (i == j) continue;
        if (dist[i][j] <= firstMin) {
            secondMin = firstMin;
            firstMin = dist[i][j];
        } else if (dist[i][j] <= secondMin) {
            secondMin = dist[i][j];
        }
    }
    return secondMin;
}

void tspBranchAndBound(const vector<vector<int>>& dist, vector<bool>& visited, int currBound, 
                       int currWeight, int level, vector<int>& currPath, vector<int>& finalPath, int& minCost) {
    
    if (level == N) {
        if (dist[currPath[level - 1]][currPath[0]] != 0) {
            int currCost = currWeight + dist[currPath[level - 1]][currPath[0]];
            if (currCost < minCost) {
                minCost = currCost;
                finalPath = currPath;
                finalPath.push_back(currPath[0]);
            }
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[currPath[level - 1]][i] != 0) {
            int temp = currBound;
            currWeight += dist[currPath[level - 1]][i];

            if (level == 1) {
                currBound -= ((findMinEdgeCost(dist, currPath[level - 1]) + findMinEdgeCost(dist, i)) / 2);
            } else {
                currBound -= ((findSecondMinEdgeCost(dist, currPath[level - 1]) + findMinEdgeCost(dist, i)) / 2);
            }

            if (currBound + currWeight < minCost) {
                currPath[level] = i;
                visited[i] = true;

                tspBranchAndBound(dist, visited, currBound, currWeight, level + 1, currPath, finalPath, minCost);
            }

            currWeight -= dist[currPath[level - 1]][i];
            currBound = temp;
            fill(visited.begin(), visited.end(), false);
            for (int j = 0; j <= level - 1; j++) {
                visited[currPath[j]] = true;
            }
        }
    }
}

void tsp(const vector<vector<int>>& dist) {
    vector<int> currPath(N + 1);
    vector<int> finalPath(N + 1);
    vector<bool> visited(N, false);

    int currBound = 0;
    for (int i = 0; i < N; i++) {
        currBound += (findMinEdgeCost(dist, i) + findSecondMinEdgeCost(dist, i));
    }

    currBound = (currBound & 1) ? (currBound / 2 + 1) : (currBound / 2);

    visited[0] = true;
    currPath[0] = 0;

    int minCost = INT_MAX;
    tspBranchAndBound(dist, visited, currBound, 0, 1, currPath, finalPath, minCost);

    cout << "Minimum tour cost: " << minCost << endl;
    cout << "Path taken: ";
    for (int i = 0; i <= N; i++) {
        cout << finalPath[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    tsp(dist);

    return 0;
}
