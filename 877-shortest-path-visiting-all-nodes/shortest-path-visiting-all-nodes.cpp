class Solution {
public:

    // Performs Multi-Source BFS with Bitmasking
    // Returns the shortest path that visits every node
    int solve(vector<vector<int>>& g) {

        int n = g.size();

        // Bitmask representing all nodes visited
        // Example: n = 4 -> 1111 (15)
        int all = (1 << n) - 1;

        // Queue stores:
        // {currentNode, {distance, visitedMask}}
        queue<pair<int, pair<int, int>>> q;

        // Visited states
        // A state is uniquely identified by:
        // (current node, visited mask)
        set<pair<int, int>> vis;

        // -------------------------------------------------
        // Multi-Source BFS
        // Start BFS from every node because
        // the shortest path can begin anywhere.
        // -------------------------------------------------
        for (int i = 0; i < n; i++) {

            // Initially only ith node is visited
            int mask = (1 << i);

            q.push({i, {0, mask}});
            vis.insert({i, mask});
        }

        // Standard BFS
        while (!q.empty()) {

            auto node = q.front();
            q.pop();

            int val  = node.first;          // Current node
            int dist = node.second.first;   // Distance travelled
            int mask = node.second.second;  // Nodes visited so far

            // Traverse all neighbours
            for (auto nbr : g[val]) {

                // Mark neighbour as visited
                int newMask = mask | (1 << nbr);

                // If every node has been visited,
                // we've found the shortest answer
                if (newMask == all)
                    return dist + 1;

                // Skip if this exact state
                // (node + visited mask) was already processed
                if (vis.count({nbr, newMask})) {
                    continue;
                }
                else {

                    // Push new state into BFS
                    q.push({nbr, {dist + 1, newMask}});

                    // Mark state as visited
                    vis.insert({nbr, newMask});
                }
            }
        }

        return 0;
    }

    int shortestPathLength(vector<vector<int>>& graph) {

        int n = graph.size();

        // Only one node exists,
        // already visited.
        if (n == 1)
            return 0;

        return solve(graph);
    }
};