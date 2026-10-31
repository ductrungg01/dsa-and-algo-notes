#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> color(V, 0); // 0: unvisited, 1 and -1: two different colors

    queue<int> q;

    // Iterate through all vertices to handle disconnected components
    for (int i = 0; i < V; ++i) {
        if (color[i] != 0) continue;

        // Assign the first color to the starting vertex
        color[i] = 1;
        q.push(i);

        // BFS to color all vertices in the current component
        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int v : graph[u]) {
                // A self-loop makes the graph non-bipartite
                if (u == v) return false;

                // Adjacent vertices cannot have the same color
                if (color[v] * color[u] == 1) return false;

                // Skip vertices that have already been colored
                if (color[v] != 0) continue;

                // Assign the opposite color to the neighbor
                color[v] = -1 * color[u];
                q.push(v);
            }
        }
    }

    return true;
}

int main() {
    vector<vector<int>> graph1 = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };

    vector<vector<int>> graph2 = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    cout << boolalpha; // Print boolean values as true/false instead of 1/0

    cout << "Graph 1: " << isBipartite(graph1) << '\n';
    cout << "Graph 2: " << isBipartite(graph2) << '\n';

    return 0;
}