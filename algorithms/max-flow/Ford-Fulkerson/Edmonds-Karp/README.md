# Edmonds-Karp Algorithm

This implementation is based on the following explanation:

[GeeksforGeeks - Ford-Fulkerson Algorithm for Maximum Flow Problem](https://www.geeksforgeeks.org/dsa/ford-fulkerson-algorithm-for-maximum-flow-problem/?utm_source=chatgpt.com)

The code is rewritten in a simpler way to make it easier for me to understand and remember.

## Note

Using **BFS** to select augmenting paths makes this implementation the **Edmonds-Karp** variant of the Ford-Fulkerson method.

## Idea

1. Use **BFS** to find an augmenting path from source to sink.
2. Find the **minimum residual capacity** along the path.
3. Update the forward and reverse edges.
4. Repeat until there is no augmenting path.

### Complexity

```text
O(V × E²)
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
