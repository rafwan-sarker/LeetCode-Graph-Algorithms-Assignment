// LeetCode #1584 - Min Cost to Connect All Points
// Algorithm: Kruskal's Algorithm (Minimum Spanning Tree) with Union-Find
//
// Idea: every point starts as its own group. Build every possible edge
// with its Manhattan-distance cost, sort cheapest first, and add each
// edge only if it connects two groups that aren't already connected.
// Stop once all points are in one group (n - 1 edges used).

class Solution {
    vector<int> parent;                          // parent[i] = i's group leader

    int find(int x) {                            // which group does x belong to?
        if (parent[x] != x)                      // if x isn't its own leader...
            parent[x] = find(parent[x]);         // ...follow the chain up (and shortcut it)
        return parent[x];                        // return the group's top leader
    }

    bool unite(int a, int b) {                   // try to merge a's and b's groups
        int ra = find(a), rb = find(b);          // leaders of each group
        if (ra == rb) return false;              // already connected -> skip
        parent[ra] = rb;                         // merge the two groups
        return true;                             // we connected two separate groups
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();                   // number of points
        parent.assign(n, 0);                     // make the parent array size n
        for (int i = 0; i < n; i++) parent[i] = i;  // each point starts alone

        vector<array<int,3>> edges;              // all edges: {cost, i, j}
        for (int i = 0; i < n; i++)              // first point of the pair
            for (int j = i + 1; j < n; j++)      // every later point (no duplicates)
                edges.push_back({
                    abs(points[i][0] - points[j][0]) +   // |x1 - x2|
                    abs(points[i][1] - points[j][1]),     // + |y1 - y2| = cost
                    i, j
                });

        sort(edges.begin(), edges.end());        // cheapest edges first

        int total = 0, used = 0;                 // running cost, edges kept
        for (auto& e : edges) {                  // go cheapest -> most expensive
            if (unite(e[1], e[2])) {             // kept only if it joins two groups
                total += e[0];                   // add this edge's cost
                if (++used == n - 1) break;      // n points need n-1 edges
            }
        }
        return total;                            // minimum total cost
    }
};
