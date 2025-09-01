# 📘 Introduction to Graph Theory: A Computer Science Perspective

This video offers a comprehensive introduction to graph theory, emphasizing its relevance in computer science. It blends formal definitions, real-world applications, and visual intuition to build a strong foundational understanding.

---

## 🎯 Why Study Graph Theory?

Graph theory is everywhere—from obvious domains like navigation to surprising ones like puzzles.

- **Navigation Systems**  
  - Intersections = vertices  
  - Roads = edges  
  - Finding shortest paths = graph algorithms  
  - Example: GPS routing

- **Social Networks**  
  - People = nodes  
  - Friendships = edges  
  - Friend recommendations = graph traversal

- **Sudoku Puzzle**  
  - Cells = vertices  
  - Constraints = edges  
  - Solving = graph coloring  
  - Each number is treated as a color; constraints ensure no repeats in rows, columns, or subgrids

---

## 🧩 Formal Definition of a Graph

A graph is defined as:

```math
G = (V, E)
```

Where:
- **V** is the set of vertices (e.g., `{0, 1, 2, 3, 4}`)
- **E** is the set of edges (e.g., `{(0,1), (0,2), (0,3), (1,3), (2,3), (3,4)}`)

---

## 🧠 Key Terminology

- **Vertex (Node)**: Fundamental unit of a graph  
- **Edge**: Connection between two vertices  
- **Neighbors**: Vertices connected by an edge  
- **Degree**: Number of edges connected to a vertex  
- **Path**: Sequence of vertices connected by edges  
- **Cycle**: Path that starts and ends at the same vertex  
- **Connectivity**:  
  - Two vertices are connected if a path exists between them  
  - A graph is connected if all vertex pairs have paths  
  - **Connected Component**: A subset of vertices that are connected

---

## 🧮 Types of Graphs

| Type                  | Description                                                                 |
|-----------------------|------------------------------------------------------------------------------|
| Undirected Graph      | Edges have no direction (A—B implies B—A)                                   |
| Directed Graph        | Edges have direction (A → B ≠ B → A)                                        |
| Directed Cyclic Graph | Directed graph with cycles                                                  |
| DAG                   | Directed Acyclic Graph; used in scheduling and dependency resolution        |
| Weighted Graph        | Edges have weights (e.g., distance, cost)                                   |
| Tree                  | A connected acyclic graph with special properties:                          |
|                       | - Removing any edge disconnects the graph                                   |
|                       | - Adding any edge creates a cycle                                           |

---

## 🧑‍💻 Graph Representations in Code

### 1. Adjacency Matrix
- 2D array where `matrix[i][j] = 1` if edge exists, else `0`
- Good for dense graphs

### 2. Edge Set
- List of all edges as vertex pairs
- Less common due to difficulty in querying neighbors

### 3. Adjacency List (Most Common)
```python
graph = {
    0: [1, 2, 3],
    1: [0, 3],
    2: [0, 3],
    3: [0, 1, 2, 4],
    4: [3]
}
```
- Efficient for sparse graphs  
- Easy to access neighbors  
- Saves memory

---

## 🧪 Interesting Graph Problems

- **Connectivity**: Is there a path between two vertices? Is the graph fully connected?
- **Shortest Path**: Find the path with the least number of edges or lowest weight
- **Cycle Detection**: Does a cycle exist in the graph?
- **Graph Coloring**: Assign colors to vertices so no neighbors share the same color
- **Eulerian Path**: Path that uses every edge exactly once
- **Hamiltonian Path**: Path that uses every vertex exactly once  
  - No known efficient algorithm for this (related to P vs NP)

---

## 🧠 Recap of Big Ideas

- Graph theory models relationships and constraints
- It appears in both expected and surprising applications
- Formal definitions and terminology build the foundation
- Graphs are represented in multiple ways, each with trade-offs
- Many problems in CS are graph problems at their core

