#include "bits/stdc++.h"
using namespace std;

int n;                  // number of vertices on the left side
int k;                  // number of vertices on the right side
int m;                  // number of edges
vector<vector<int>> g;  // adjacency list of the bipartite graph
vector<int> match;      // match[i] = vertex (on the left side) matched with i (on the right side)

vector<bool> used;      // used[i] = true if vertex i on the left side is visited in the 'current' DFS

bool try_kuhn(int v)
{
    if (used[v])
        return false;

    used[v] = true;

    // Try to match v with each adjacent right vertex
    for (int to : g[v])
    {
        // Case 1: 'to' is currently unmatched
        // Case 2: 'to' is matched, but its current partner can be reassigned
        if (match[to] == -1 || try_kuhn(match[to]))
        {
            match[to] = v; // Match right vertex 'to' with left vertex 'v'
            return true;
        }
    }

    // No augmenting path (duong tang cuong) was found
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> k;
    cin >> m;

    g.assign(n, vector<int>());
    match.assign(k, -1); // Initialize all right vertices as unmatched

    // Read edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // Convert 1-based index to 0-based index
        --u;
        --v;

        g[u].push_back(v);
    }

    // Try to find a matching for each left vertex
    for (int v = 0; v < n; v++)
    {
        used.assign(n, false);  // Reset visited status for the current DFS
        try_kuhn(v);            // Attempt to find an augmenting path starting from vertex 'v'
    }

    // Count the number of matched pairs
    int match_count = 0;

    // Print all matched pairs
    for (int i = 0; i < k; i++)
    {
        if (match[i] != -1)
        {
            cout << match[i] + 1 << " " << i + 1 << "\n"; // Convert back to 1-based index for output
            match_count++;
        }
    }

    cout << "Total matched pairs: " << match_count << "\n"; // Print the total number of matched pairs

    return 0;
}