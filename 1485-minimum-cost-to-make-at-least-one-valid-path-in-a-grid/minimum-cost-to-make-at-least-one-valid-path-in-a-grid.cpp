class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        // Number of rows and columns
        int n = grid.size();
        int m = grid[0].size();

        // Directions:
        // 0 -> Right
        // 1 -> Left
        // 2 -> Down
        // 3 -> Up
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        // cost[r][c] = Minimum cost required to reach cell (r, c)
        vector<vector<int>> cost(n, vector<int>(m, 1e9));

        // Min Heap:
        // {current_cost, {row, col}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        // Start from the top-left cell with cost = 0
        pq.push({0, {0, 0}});
        cost[0][0] = 0;

        // Standard Dijkstra's Algorithm
        while (!pq.empty()) {

            // Extract the cell with the smallest current cost
            auto it = pq.top();
            pq.pop();

            int curr_cost = it.first;
            int dx = it.second.first;
            int dy = it.second.second;

            // If destination is reached, this is the minimum possible cost
            if (dx == n - 1 && dy == m - 1)
                return curr_cost;

            // Skip outdated entries in the priority queue
            if (cost[dx][dy] < curr_cost)
                continue;

            // Try moving in all four possible directions
            for (int i = 0; i < 4; i++) {

                int new_r = dx + dr[i];
                int new_c = dy + dc[i];

                // Check if the new cell is inside the grid
                if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m) {

                    // If we move in the direction already indicated by the
                    // current cell, cost = 0.
                    // Otherwise, we must change the direction, so cost = 1.
                    int new_cost = (grid[dx][dy] == i + 1) ? 0 : 1;

                    // Relax the edge if a cheaper path is found
                    if (curr_cost + new_cost < cost[new_r][new_c]) {

                        cost[new_r][new_c] = curr_cost + new_cost;

                        // Push the updated state into the priority queue
                        pq.push({curr_cost + new_cost, {new_r, new_c}});
                    }
                }
            }
        }

        // Destination cannot be reached
        return -1;
    }
};

/*
Time Complexity:
O((N * M) * log(N * M))
- There are N*M cells.
- Each cell can be inserted into the priority queue.
- Every push/pop operation takes log(N*M).

Space Complexity:
O(N * M)
- Cost matrix: O(N*M)
- Priority queue: O(N*M) in the worst case.
*/