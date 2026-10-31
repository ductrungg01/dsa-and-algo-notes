#include <bits/stdc++.h>
using namespace std;

constexpr int MAXP = 1005;
constexpr int MAXK = 25;

int nk, np;

// slotTopic: left side of the bipartite graph.
// Topic t needs cap[t] questions, so we split it into cap[t] "slots".
// slotTopic[s] = the topic that slot s belongs to.
// Example: cap = {2, 1} -> slotTopic = {1, 1, 2}
vector<int> slotTopic;

// topicQuestions[t]: questions that can belong to topic t (right side of the graph).
// Every slot of topic t is connected to all questions in topicQuestions[t].
vector<int> topicQuestions[MAXK];

int match[MAXP]; // match[q]: slot currently matched with question q (-1 if free)
bool vis[MAXP];  // vis[q]: question q already visited in the current DFS

bool try_kuhn(int slot)
{
    const int topic = slotTopic[slot];
    for (int question : topicQuestions[topic])
    {
        if (vis[question])
            continue;
        vis[question] = true;

        if (match[question] == -1 || try_kuhn(match[question]))
        {
            match[question] = slot;
            return true;
        }
    }

    return false;
}

void read_input()
{
    for (int t = 1; t <= nk; ++t)
    {
        int c; cin >> c;
        // Create c slots for topic t
        while (c--)
            slotTopic.push_back(t);

        topicQuestions[t].clear();
    }

    // Each question line: k followed by k topics it may belong to.
    // We store it in reverse: topic -> list of questions.
    for (int q = 0; q < np; ++q)
    {
        int k; cin >> k;
        while (k--)
        {
            int t; cin >> t;
            topicQuestions[t].push_back(q);
        }
    }
}

// Every slot must be matched, otherwise the requirement cannot be met.
bool can_match_all()
{
    for (int s = 0; s < slotTopic.size(); ++s)
    {
        memset(vis, false, sizeof(vis));

        if (!try_kuhn(s))
            return false;
    }

    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> nk >> np)
    {
        if (nk == 0 && np == 0)
            break;

        slotTopic.clear();
        read_input();

        memset(match, -1, sizeof(match));

        if (!can_match_all())
        {
            cout << "0\n";
            continue;
        } 
        else 
        {
            // Group matched questions by topic
            vector<int> res[MAXK];
            for (int q = 0; q < np; ++q)
                res[slotTopic[match[q]]].push_back(q + 1); // +1 for 1-based indexing
    
            cout << "1\n";
            for (int t = 1; t <= nk; ++t)
            {
                for (int i : res[t])
                    cout << i << " ";
                cout << "\n";
            }
        }
    }

    return 0;
}