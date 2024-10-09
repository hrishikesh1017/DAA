#include<iostream>
#include<climits>
#include<vector>

using namespace std;

void floyd(int V, vector<vector<int>>& graph){
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if (graph[i][j]!=0){
                dist[i][j]=graph[i][j];
            }
        }
    }

    for(int k=0;k<V;k++){
        for(int i=0;i<V; i++){
            for(int j=0; j<V; j++){
                if (dist[i][k]!= INT_MAX && dist[k][j]!=INT_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if (dist[i][j]==INT_MAX){
                cout<<"inf";
            }
            else{
                cout<<dist[i][j];
            }
        }
        cout<<endl;
    }
}

int main(){
    int V = 4;
    const int INF = INT_MAX;
    vector<vector<int>> graph = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };
    floyd(V, graph);
}