class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        int row = 0, col = 0;
        int dir = 0;

        for (int num = 1; num <= n * n; num++) {
            ans[row][col] = num;
            visited[row][col] = true;

            int nr = row + dx[dir];
            int nc = col + dy[dir];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n ||
                visited[nr][nc]) {
                dir = (dir + 1) % 4;
            }

            row += dx[dir];
            col += dy[dir];
        }

        return ans;
    }
};