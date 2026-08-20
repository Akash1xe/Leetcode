class Solution {
public:
    int n;

    int dr[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dc[8] = {1, -1, 1, -1, 2, -2, 2, -2};

    double solve(int row, int col, int k, vector<vector<vector<double>>>& dp) {

        if (k == 0) {
            return 1.0;
        }

        if (dp[row][col][k] != -1.0) {
            return dp[row][col][k];
        }

        double probability = 0.0;

        for (int i = 0; i < 8; i++) {

            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < n) {

                probability += solve(newRow, newCol, k - 1, dp);
            }
        }

        return dp[row][col][k] = probability / 8.0;
    }

    double knightProbability(int n, int k, int row, int column) {

        this->n = n;

        vector<vector<vector<double>>> dp(
            n, vector<vector<double>>(n, vector<double>(k + 1, -1.0))
        );

        return solve(row, column, k, dp);
    }
};