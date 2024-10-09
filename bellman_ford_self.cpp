#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> bellman_Ford(int V, vector<vector<int>>&edges, int S){
    vector<int>dist(V, 1e8);
    dist[S] = 0;
    for(int i=0; i<V-1; i+=1){
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(dist[u] != INT_MAX && dist[u]+wt<dist[v]){
                dist[v] = dist[u]+wt;
            }
        }
    }
    return dist;
}

int main(){
    vector<vector<int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3},
        {1, 3, 2}, {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };
    vector<int> result = bellman_Ford(5, edges, 0);

    for(auto dist: result){
        cout<<dist<<" ";
    }
}