#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

const long long INF = LLONG_MAX;  

int tsp(const vector<vector<int>>& dist) {
    int n = dist.size();
    vector<vector<long long>> dp(1 << n, vector<long long>(n, INF));
    
    for (int i = 1; i < n; i++) {
        dp[1 << i][i] = dist[0][i];
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j) && i != j) {
                        dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + dist[j][i]);
                    }
                }
            }
        }
    }

    long long result = INF;
    for (int i = 1; i < n; i++) {
        result = min(result, dp[(1 << n) - 1][i] + dist[i][0]);
    }
    
    return result+1;
}

int main() {
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Minimum tour cost: " << tsp(dist) << endl;
    return 0;
}
