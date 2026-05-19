# LeetCode-Graph-Algorithms-Assignment
Solutions to two graph problems.

## Problem 1: Min Cost to Connect All Points (LeetCode #1584)
- **Algorithm:** Kruskal's Algorithm (Minimum Spanning Tree)
- **File:** MinCostConnectPoints.cpp
- Builds all edges, sorts by Manhattan distance, and uses Union-Find
  to add the cheapest edges that don't form a cycle.

## Problem 2: Cheapest Flights Within K Stops (LeetCode #787)
- **Algorithm:** Bellman-Ford Algorithm (shortest path with a stop constraint)
- **File:** CheapestFlights.cpp
- Relaxes all edges k+1 times using a frozen copy each round so the
  stop limit is never exceeded.
