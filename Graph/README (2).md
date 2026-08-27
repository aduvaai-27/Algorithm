# Dijkstra's Algorithm — Graph Representation Comparison

This repo implements **Dijkstra's Shortest Path Algorithm** using three different graph representations:

1. **Adjacency List** 
2. **Edge List** 
3. **Adjacency Matrix** 

All three versions solve the exact same problem — single-source shortest path on a weighted, undirected graph — using a min-priority-queue (`priority_queue` with `greater<>`) based Dijkstra. The only thing that changes across versions is **how the graph is stored** and **how neighbors of a node are discovered**, which directly affects performance.

---

## 1. Adjacency List

```cpp
vector<vector<pair<int, int>>> graph(node + 1);
```

Each node stores a list of `(neighbor, weight)` pairs.

**Neighbor lookup:** Directly iterate `graph[u]` — only the actual edges of `u`.

### Complexity
| Metric | Complexity |
|---|---|
| Space | O(V + E) |
| Building the graph | O(E) |
| Finding neighbors of a node | O(deg(u)) |
| Overall Dijkstra (with binary heap) | **O((V + E) log V)** |

### Advantages
- Most efficient for **sparse graphs** (E << V²), which is the most common case in real-world graphs.
- Neighbor iteration only touches real edges — no wasted work on non-existent edges.
- Memory usage scales with actual number of edges, not V².

### Disadvantages
- Slightly more complex to set up (vector of vectors of pairs).
- Checking if a specific edge `(u, v)` exists is O(deg(u)) instead of O(1).

### When to use
✅ Default choice for almost all graph problems, especially large sparse graphs (social networks, road networks, etc.). This is the **industry-standard representation** for Dijkstra.

---

## 2. Edge List

```cpp
vector<Edge> graph(edge); // Edge = {u, v, w}
```

The graph is stored as a flat list of all edges, with no per-node grouping.

**Neighbor lookup:** For every popped node `s`, the code performs a **linear scan over the entire edge list** to find edges where `graph[i].u == s`.

```cpp
for (int i = 0; i < edge; i++) {
    if (graph[i].u != s) continue;
    ...
}
```

### Complexity
| Metric | Complexity |
|---|---|
| Space | O(E) |
| Building the graph | O(E) |
| Finding neighbors of a node | O(E) — full scan every time |
| Overall Dijkstra | **O(V · E)** in the worst case (each of up to V pops scans all E edges), can be even worse with duplicate pq entries |

### Advantages
- Very simple structure — easy to read/write/store as raw edge data.
- Great for algorithms that need to process **all edges** rather than per-node neighbors (e.g., Bellman-Ford, Kruskal's MST).
- Good for serialization / input-output / storing sparse graph data compactly.

### Disadvantages
- **Very inefficient for Dijkstra** — no way to jump directly to a node's neighbors, so every relaxation step costs O(E) instead of O(deg(u)).
- Also note: this implementation only pushes edges in one direction (`u -> v`), so it does **not** correctly handle the graph as undirected the way the other two do — worth fixing if undirected traversal is required.

### When to use
⚠️ Not recommended for Dijkstra. Edge lists are the right structure for **Bellman-Ford** and **Kruskal's MST**, where you naturally need to process every edge once per pass. For Dijkstra specifically, this representation defeats the purpose of using a priority queue for efficient relaxation.

---

## 3. Adjacency Matrix

```cpp
vector<vector<int>> graph(node, vector<int>(node, 0));
```

A `V x V` matrix where `graph[u][v]` stores the edge weight (0 = no edge).

**Neighbor lookup:** For every popped node `u`, scan the **entire row** `graph[u][0..V-1]`.

### Complexity
| Metric | Complexity |
|---|---|
| Space | **O(V²)** — regardless of how many edges actually exist |
| Building the graph | O(E) to insert, but O(V²) to allocate/initialize |
| Finding neighbors of a node | O(V) — scans the whole row every time |
| Overall Dijkstra | **O(V² + V log V)** ≈ **O(V²)** for dense graphs |

### Advantages
- O(1) edge lookup — checking if `(u, v)` exists is a single array access.
- Simple to implement and reason about, especially for small graphs.
- Well-suited for **dense graphs** (E close to V²), where the matrix isn't wasting much space anyway.

### Disadvantages
- O(V²) space even if the graph is sparse — wasteful for large sparse graphs.
- Row scan makes each relaxation step O(V), not O(deg(u)), so it's slower than adjacency list whenever the graph is sparse.
- Doesn't scale well: a graph with 10,000 nodes needs a 10,000 x 10,000 matrix (100 million ints) even if it only has a few thousand edges.

### When to use
✅ Good for small or dense graphs, or when you frequently need O(1) "does edge (u,v) exist?" queries (e.g. Floyd-Warshall, small competitive programming problems where V is small).
❌ Avoid for large or sparse graphs.

---

## Side-by-Side Summary

| | Adjacency List | Edge List | Adjacency Matrix |
|---|---|---|---|
| **Space** | O(V + E) | O(E) | O(V²) |
| **Neighbor lookup** | O(deg(u)) | O(E) | O(V) |
| **Dijkstra time (overall)** | **O((V+E) log V)** ✅ best | O(V·E) ❌ worst | O(V² ) |
| **Edge existence check (u,v)** | O(deg(u)) | O(E) | O(1) ✅ |
| **Best for** | Sparse graphs (general purpose) | Algorithms needing all-edges pass (Bellman-Ford, Kruskal) | Dense/small graphs |
| **Worst for** | Very dense graphs (matrix wins on constant factor) | Any priority-queue based shortest-path algorithm | Large sparse graphs |

---

## Conclusion

- **Adjacency List → Best overall choice for Dijkstra.** It pairs naturally with the priority-queue-based relaxation approach, giving the standard `O((V + E) log V)` complexity.
- **Edge List → Not ideal for Dijkstra.** It's structurally mismatched with per-node relaxation since there's no fast way to get a node's neighbors; better reserved for Bellman-Ford or Kruskal's MST.
- **Adjacency Matrix → Fine for small/dense graphs**, but wastes memory and time on sparse graphs due to the O(V²) space and O(V) neighbor scan per node.

**Rule of thumb:** if V is large and the graph is sparse (which is true for most real-world graphs) → use **Adjacency List**. If V is small or the graph is nearly complete → **Adjacency Matrix** is acceptable. Reserve **Edge List** for algorithms that are explicitly edge-centric.
