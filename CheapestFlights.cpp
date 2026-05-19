// LeetCode #787 - Cheapest Flights Within K Stops
// Algorithm: Bellman-Ford (shortest path with a stop constraint)
//
// Idea: keep a price tag per city = cheapest price found so far to
// reach it. Start city = 0, all others = "infinity" (unknown).
// Repeat k+1 rounds (k stops = at most k+1 flights). Each round uses
// a frozen copy of the prices so only ONE more flight is added per
// round, which keeps the stop limit honest.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        const int INF = 1e9;                 // "no known way here yet"

        vector<int> dist(n, INF);            // price tag per city, start unknown
        dist[src] = 0;                       // start city costs $0

        for (int i = 0; i <= k; i++) {       // k+1 rounds = one more flight each
            vector<int> temp = dist;         // frozen copy for this round
            for (auto& f : flights) {        // check every flight
                int from = f[0];             // flight leaves from here
                int to   = f[1];             // flight arrives here
                int price = f[2];            // flight cost
                if (dist[from] != INF &&     // can we even reach 'from'?
                    dist[from] + price < temp[to])  // cheaper than 'to's best?
                    temp[to] = dist[from] + price;  // record the cheaper price
            }
            dist = temp;                     // commit this round's improvements
        }

        return dist[dst] == INF ? -1 : dist[dst];  // unreachable -> -1, else price
    }
};
