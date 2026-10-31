# Refs
- https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html
- https://www.geeksforgeeks.org/dsa/maximum-bipartite-matching/
- https://www.geeksforgeeks.org/problems/maximum-bipartite-matching--170646/1

# Kuhn's Algorithm

Kuhn's Algorithm is used to find the **Maximum Bipartite Matching** in a bipartite graph.

## Idea

The graph is divided into two disjoint sets of vertices: Left and Right. Edges only connect vertices from different sets.

The algorithm works by:

1. Starting with an empty matching.
2. Iterating through each vertex in the Left partition.
3. Trying to find an unmatched vertex in the Right partition.
4. If the target vertex is already matched, recursively trying to find another match for its current partner.
5. If an **Augmenting Path** is found, update the matching to increase its size by one.

The algorithm stops when no more augmenting paths can be found.

## Complexity

- **Time:** O(V × E), where V is the number of vertices in the Left partition and E is the number of edges.
- **Space:** O(V + E) for the adjacency list and auxiliary data structures.

## Is It Brute Force?

Although Kuhn's Algorithm repeatedly tries to find possible matches, it is not brute force.

Unlike brute force, which enumerates all possible matchings, Kuhn's Algorithm:

- Builds the matching incrementally.
- Reuses the current matching instead of starting over.
- Uses Augmenting Paths to improve the existing matching.
- Avoids exploring every possible combination.

It is a graph algorithm based on augmenting paths, guaranteeing a maximum matching when no further augmenting path exists.