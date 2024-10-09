#include <iostream>
#include<vector>
#include<climits>
#include<chrono>

using namespace std;

void bellman(vector<vector<int>>&edges, int V, int src){
    vector<int>dist(V,INT_MAX);
    dist[src] = 0;
    for(int i=0; i<V-1; i++){
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if( dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                dist[v] =  dist[u]+w;  
            }
        }
    }
    for (auto d: dist){
        cout<<d<<" ";
    }
}

int main(){
    vector<vector<int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3},
        {1, 3, 2}, {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };
    bellman(edges,5, 0);    
}