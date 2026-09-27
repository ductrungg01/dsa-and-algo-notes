// https://www.geeksforgeeks.org/dsa/ford-fulkerson-algorithm-for-maximum-flow-problem/
// Note: Using BFS to select augmenting paths makes this implementation the Edmonds-Karp variant of the Ford-Fulkerson method.
// O(V.E^2)

#include <bits/stdc++.h>
using namespace std;

// Finds an augmenting path from source to sink in the residual graph
bool bfs(vector<vector<int>> &rGraph, int src, int sink,
         vector<int> &parent) {

    int V = rGraph.size();

    vector<bool> vis(V, false);
    queue<int> q;

    q.push(src);
    vis[src] = true;
    parent[src] = -1;

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        // Explore all adjacent vertices
        for (int v = 1; v < V; v++) {

            // Visit only unvisited vertices having positive residual capacity
            if (!vis[v] && rGraph[u][v] > 0) {

                vis[v] = true;
                parent[v] = u;

                // Sink reached, augmenting path found
                if (v == sink)
                    return true;

                q.push(v);
            }
        }
    }

    return false;
}

// Returns the maximum flow from source (1) to sink (V)
int findMaxFlow(int V, vector<vector<int>> &edges) {

    // Capacity graph
    vector<vector<int>> graph(V + 1, vector<int>(V + 1, 0));

    for (auto &edge : edges) {

        int u = edge[0];
        int v = edge[1];
        int cap = edge[2];

        graph[u][v] = cap;
    }

    // Residual graph initially equals the capacity graph
    vector<vector<int>> rGraph = graph;

    int src = 1;
    int sink = V;

    vector<int> parent(V + 1);
    int maxFlow = 0;

    // Keep finding augmenting paths
    while (bfs(rGraph, src, sink, parent)) {

        int pathFlow = INT_MAX;

        // Find bottleneck capacity of the current path
        for (int v = sink; v != src; v = parent[v]) {

            int u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        // Update residual capacities of forward and reverse edges
        for (int v = sink; v != src; v = parent[v]) {

            int u = parent[v];

            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        // Add path flow to the total maximum flow
        maxFlow += pathFlow;
    }

    return maxFlow;
}

void solve(){
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;
    edges.reserve(E);
    while (E--){
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }

    cout << findMaxFlow(V, edges) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int testcase = 1;
    cin >> testcase;

    while (testcase--) {
        solve();
    }

    return 0;
}
