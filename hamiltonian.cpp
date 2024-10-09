#include <iostream>
#include <vector>

using namespace std;

// Function to check if the vertex v can be added at index 'pos' in the Hamiltonian Cycle
bool isSafe(int v, const vector<vector<int>>& graph, vector<int>& path, int pos) {
    // Check if the current vertex is adjacent to the previously added vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Recursive function to find the Hamiltonian Cycle
bool hamiltonianCycleUtil(vector<vector<int>>& graph, vector<int>& path, int pos) {
    int V = graph.size();

    // Base case: If all vertices are included in the path
    if (pos == V) {
        // Check if there is an edge from the last vertex to the first vertex
        return graph[path[pos - 1]][path[0]] == 1;
    }

    // Try different vertices as the next candidate in the Hamiltonian Cycle
    for (int v = 1; v < V; v++) {  // Vertex 0 is already in the path, so start from 1
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamiltonianCycleUtil(graph, path, pos + 1))
                return true;

            // Backtrack if adding vertex v doesn't lead to a solution
            path[pos] = -1;
        }
    }

    // If no vertex can be added, return false
    return false;
}

// Function to solve the Hamiltonian Cycle problem
bool hamiltonianCycle(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> path(V, -1);

    // Start from vertex 0
    path[0] = 0;

    // Check if a Hamiltonian Cycle exists
    if (!hamiltonianCycleUtil(graph, path, 1)) {
        cout << "No Hamiltonian Cycle exists." << endl;
        return false;
    }

    // If there is a solution, print the path
    cout << "Hamiltonian Cycle: ";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    // Return to the starting vertex to complete the cycle
    cout << path[0] << endl;

    return true;
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCycle(graph);

    return 0;
}
