# Dinic's Algorithm

This implementation is based on the following explanation:

[GeeksforGeeks - Dinic's Algorithm for Maximum Flow](https://www.geeksforgeeks.org/dsa/dinics-algorithm-maximum-flow/)

The code is rewritten in a simpler way to make it easier for me to understand and remember.

## Idea

Dinic's algorithm uses:

1. **BFS** to build the level graph.
2. **DFS** to send flow through valid edges.
3. Repeat until the sink is no longer reachable.

### Complexity

```text
O(V² × E)
```

Where:

* `V` = number of vertices
* `E` = number of edges

## Run

Compile:

```bash
g++ main.cpp -o main
```

Run:

```bash
./main
```
