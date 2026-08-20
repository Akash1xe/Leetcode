class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {

        // dp[moves][r][c]
        // dp[m][r][c] = probability that the knight
        // is still on the board after m moves
        // starting from cell (r, c)

        vector<vector<vector<double>>> dp(
            k + 1,
            vector<vector<double>>(n, vector<double>(n, 0.0))
        );

        // Base case:
        // With 0 moves, knight is definitely on board
        // from every valid cell.
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                dp[0][r][c] = 1.0;
            }
        }

        // 8 possible knight moves
        int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

        // Build the table for 1 to k moves
        for (int moves = 1; moves <= k; moves++) {

            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {

                    // Try all 8 knight moves
                    for (int i = 0; i < 8; i++) {

                        int nr = r + dr[i];
                        int nc = c + dc[i];

                        // If next position is inside board
                        if (nr >= 0 && nr < n &&
                            nc >= 0 && nc < n) {

                            dp[moves][r][c] +=
                                dp[moves - 1][nr][nc] / 8.0;
                        }
                    }
                }
            }
        }

        return dp[k][row][column];
    }
};