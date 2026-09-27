// https://www.geeksforgeeks.org/dsa/dinics-algorithm-maximum-flow/
// O(E.V^2)

#include <bits/stdc++.h>
using namespace std;

// A structure to represent a edge between
// two vertex
struct Edge {
    int v; // Vertex v (or "to" vertex)
           // of a directed edge u-v. "From"
           // vertex u can be obtained using
           // index in adjacent array.

    int flow; // current flow of data in edge

    int C; // capacity

    int rev; // To store index of reverse
             // edge in adjacency list so that
             // we can quickly find it.
};

vector<vector<Edge>> adj;
vector<int> level;

// Add an edge u -> v with capacity C
void addEdge(int u, int v, int C) {
    // Forward edge: u -> v
    Edge a{
        v,
        0,
        C,
        (int)adj[v].size() 
    };

    // Reverse edge: v -> u
    //
    // Initially its capacity is 0
    // Later, if we send flow through u -> v,
    // this reverse edge allows us to "undo" that flow.
    Edge b{
        u,
        0,
        0,
        (int)adj[u].size()
    };

    adj[u].push_back(a);
    adj[v].push_back(b); 
}

// BFS builds the "level graph".
//
// level[v] tells us the shortest distance
// from the source to vertex v using edges
// that still have remaining capacity.
bool BFS(int s, int t) {
    fill(level.begin(), level.end(), -1);

    queue<int> q;
    q.push(s);
    level[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (Edge& e : adj[u]) {

            // We can only use an edge if:
            // 1. The destination has not been visited.
            // 2. The edge still has available capacity.
            if (level[e.v] == -1 && e.flow < e.C) {
                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
        }
    }

    // If t was reached, there is still a possible
    // path from s to t.
    return level[t] != -1;
}

// Send flow from u to t.
//
// nextEdgeIndexs[u] tells us which edge we should try next.
//
// This is important because after an edge has already
// been proven useless, we don't want to try that edge
// again during the same BFS phase.
int sendFlow(
    int u,
    int flow,
    int t,
    vector<int>& nextEdgeIndexs
) {
    // We reached the sink.
    if (u == t)
        return flow;

    while (nextEdgeIndexs[u] < (int)adj[u].size()) {

        Edge& e = adj[u][nextEdgeIndexs[u]];

        // We only move to the next level.
        //
        // This is what makes the graph a "level graph".
        if (level[e.v] == level[u] + 1 &&
            e.flow < e.C) {

            // We cannot send more than:
            // - the flow received from the previous vertex
            // - the remaining capacity of this edge
            int currFlow = min(
                flow,
                e.C - e.flow
            );

            int tempFlow = sendFlow(
                e.v,
                currFlow,
                t,
                nextEdgeIndexs
            );

            if (tempFlow > 0) {

                // Send flow through the forward edge.
                e.flow += tempFlow;

                // Also update the reverse edge.
                //
                // e.rev tells us where the reverse edge
                // is stored inside adj[e.v].
                //
                // Example:
                //
                // u -> v has flow 5
                //
                // Then the reverse edge v -> u gets -5.
                // This allows the algorithm to cancel
                // some of the previous flow later.
                adj[e.v][e.rev].flow -= tempFlow;

                return tempFlow;
            }
        }

        // This edge cannot send any more useful flow,
        // so move to the next edge.
        nextEdgeIndexs[u]++;
    }

    return 0;
}

int DinicMaxflow(int s, int t) {
    if (s == t)
        return -1;

    int totalFlow = 0;

    // Repeat while BFS can still find a path
    // from source to sink.
    while (BFS(s, t)) {

        // nextEdgeIndexs[u] = index of the next edge
        // we should try from vertex u.
        //
        // It prevents us from repeatedly checking
        // edges that have already failed.
        vector<int> nextEdgeIndexs(adj.size(), 0);

        while (true) {

            int flow = sendFlow(
                s,
                INT_MAX,
                t,
                nextEdgeIndexs
            );

            // No more flow can be sent
            // in the current level graph.
            if (flow == 0)
                break;

            totalFlow += flow;
        }
    }

    return totalFlow;
}

void solve() {
    int V, E;
    cin >> V >> E;

    // Create V empty adjacency lists.
    adj.assign(V, {});

    // level[i] = level of vertex i in BFS
    level.assign(V, -1);

    // Input:
    // u v capacity
    for (int i = 0; i < E; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        addEdge(u, v, c);
    }

    cout << DinicMaxflow(0, V - 1) << '\n';
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