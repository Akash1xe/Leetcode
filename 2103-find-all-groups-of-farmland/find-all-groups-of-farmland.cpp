class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        // Number of rows and columns
        int n = land.size();
        int m = land[0].size();

        // 4-directional movement (Right, Left, Down, Up)
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        // Stores the final answer
        vector<vector<int>> ans;

        // Queue used for BFS
        queue<pair<int, int>> q;

        // Traverse every cell of the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Found the starting cell of a new farmland
                if (land[i][j] == 1) {

                    // Top-left corner of this farmland
                    int sr = i;
                    int sc = j;

                    // Bottom-right corner (initially same as start)
                    int er = i;
                    int ec = j;

                    // Start BFS
                    q.push({i, j});

                    // Mark visited
                    land[i][j] = 0;

                    while (!q.empty()) {

                        // Get current cell
                        auto [x, y] = q.front();
                        q.pop();

                        // Update the bottom-right corner
                        er = max(er, x);
                        ec = max(ec, y);

                        // Visit all 4 neighbours
                        for (int k = 0; k < 4; k++) {

                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            // Check boundary + unvisited farmland
                            if (nx >= 0 && nx < n &&
                                ny >= 0 && ny < m &&
                                land[nx][ny] == 1) {

                                // Mark visited before pushing
                                land[nx][ny] = 0;

                                // Add neighbour to queue
                                q.push({nx, ny});
                            }
                        }
                    }

                    // Store one farmland group
                    ans.push_back({sr, sc, er, ec});
                }
            }
        }

        return ans;
    }
};