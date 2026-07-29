class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {

                    int area = 0;
                    queue<pair<int, int>> q;

                    q.push({i, j});
                    grid[i][j] = 0; // Mark as visited

                    while (!q.empty()) {

                        auto [x, y] = q.front();
                        q.pop();

                        area++;

                        for (int k = 0; k < 4; k++) {

                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if (nx >= 0 && nx < n &&
                                ny >= 0 && ny < m &&
                                grid[nx][ny] == 1) {

                                q.push({nx, ny});
                                grid[nx][ny] = 0; // Mark as visited
                            }
                        }
                    }

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};