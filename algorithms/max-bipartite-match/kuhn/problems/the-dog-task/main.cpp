#include <bits/stdc++.h>
using namespace std;

constexpr int       MAXN = 105;
constexpr double    EPS = 1e-9;

struct Point {
    double x, y;
};

int N, M;
Point bobRoutes[MAXN], interestPlaces[MAXN];
vector<int> adj[MAXN];      // adj[i]: interesting points that can be visited from segment i
int match[MAXN];            // match[j]: segment currently matched with interesting point j
bool vis[MAXN];

bool try_kuhn(int v)
{
    if (vis[v])
        return false;
        
    vis[v] = true;
    for (int to : adj[v]) {
        if (match[to] == -1 || try_kuhn(match[to])) {
            match[to] = v;
            return true;
        }
    }

    return false;
}

void solve()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> bobRoutes[i].x >> bobRoutes[i].y;
    for (int i = 0; i < M; i++)
        cin >> interestPlaces[i].x >> interestPlaces[i].y;
    
    for (int i = 0; i < N; i++) 
    {
        adj[i].clear();
    }

    // Build the bipartite graph
    for (int i = 0; i < N - 1; ++i)
    {
        // hypot return sqrt(x*x + y*y) but is more accurate and avoids overflow
        double d = hypot(bobRoutes[i + 1].x - bobRoutes[i].x, bobRoutes[i + 1].y - bobRoutes[i].y);
        for (int j = 0; j < M; ++j)
        {
            double d1 = hypot(interestPlaces[j].x - bobRoutes[i].x, interestPlaces[j].y - bobRoutes[i].y);
            double d2 = hypot(interestPlaces[j].x - bobRoutes[i + 1].x, interestPlaces[j].y - bobRoutes[i + 1].y);

            // The detour through P must not exeed twice the original segment length
            if (d1 + d2 <= 2 * d + EPS)
                adj[i].push_back(j);
        }
    }

    fill(match, match + M, -1);
    int matches = 0;

    for (int i = 0; i < N - 1; ++i) 
    {
        fill(vis, vis + N, false);
        if (try_kuhn(i))
            matches++;
    }

    cout << matches + N << "\n";
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();
    }
    return 0;
}