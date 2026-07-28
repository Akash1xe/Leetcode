class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int,int>, int>> q;

        // Push all 0's into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        // 4 directions
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            ans[row][col] = dist;

            // Visit all 4 neighbours
            for (int k = 0; k < 4; k++) {

                int newRow = row + dr[k];
                int newCol = col + dc[k];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m &&
                    !vis[newRow][newCol]) {

                    vis[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, dist + 1});
                }
            }
        }

        return ans;
    }
};