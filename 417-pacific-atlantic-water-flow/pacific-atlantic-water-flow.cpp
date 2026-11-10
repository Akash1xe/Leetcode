class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<bool>>& vis) {

        int n = heights.size();
        int m = heights[0].size();

        vis[r][c] = true;

        for (int i = 0; i < 4; i++) {

            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                continue;

            if (vis[nr][nc])
                continue;

            // Reverse flow: move to equal or greater height
            if (heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Pacific: top row and left column
        for (int i = 0; i < n; i++) {
            dfs(i, 0, heights, pacific);
        }

        for (int j = 0; j < m; j++) {
            dfs(0, j, heights, pacific);
        }

        // Atlantic: bottom row and right column
        for (int i = 0; i < n; i++) {
            dfs(i, m - 1, heights, atlantic);
        }

        for (int j = 0; j < m; j++) {
            dfs(n - 1, j, heights, atlantic);
        }

        vector<vector<int>> ans;

        // Find cells reachable from both oceans
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};