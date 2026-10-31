# Bipartite Graph

## 1. What is a Bipartite Graph?

A **bipartite graph** is a graph whose vertices can be divided into two disjoint sets, U and V, such that every edge connects a vertex in U to a vertex in V.

In other words:
- No two vertices in the same set can have an edge between them.
- Every edge must connect vertices from different sets.

A graph is bipartite if and only if it contains **no odd-length cycles**.

## 2. Real-world Applications

Bipartite graphs are useful for modeling relationships between two different types of entities.

Some practical examples:

- **Job Assignment:** Matching employees to available jobs, where employees and jobs form two separate sets.
- **Student-Course Enrollment:** Connecting students to the courses they want to attend.
- **Dating and Recommendation Systems:** Modeling compatibility between two groups of users or entities.
- **Resource Allocation:** Assigning machines to tasks or workers to projects.
- **Matching Problems:** Finding maximum matchings between two sets of vertices.

These problems can often be solved using algorithms such as Kuhn's Algorithm or Hopcroft–Karp Algorithm.

## 3. How to Check Whether a Graph Is Bipartite

A common approach is **2-coloring using BFS or DFS**.

The main idea:

1. Start from an unvisited vertex and assign it color 1.
2. Visit its neighbors and assign them the opposite color (-1).
3. Continue exploring the graph, always assigning the opposite color to each unvisited neighbor.
4. If two adjacent vertices have the same color, the graph is not bipartite.
5. If every vertex can be colored without conflicts, the graph is bipartite.

For disconnected graphs, repeat the process from every unvisited vertex.

## 4. Complexity Analysis

Let:
- V = Number of vertices.
- E = Number of edges.

| Complexity | Value | Explanation |
|---|---|---|
| Time | O(V + E) | Every vertex and edge is processed at most a constant number of times. |
| Space | O(V) | Color array and BFS queue. |

## 5. Important Properties

- Every tree is bipartite.
- Every even-length cycle is bipartite.
- A graph containing an odd-length cycle is not bipartite.
- A graph does not need to be connected to be bipartite.
- A bipartite graph can contain cycles, as long as they have even lengths.