class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int n = matrix.size();       // Number of rows
        int m = matrix[0].size();    // Number of columns

        // dp[i][j] = side length of the largest square
        // whose bottom-right corner is (i, j)
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Stores the maximum side length found
        int maxi = 0;

        // Traverse every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // We can form a square only if current cell is '1'
                if (matrix[i][j] == '1') {

                    // If we are in the first row or first column,
                    // the largest possible square has side length 1
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }

                    else {

                        // To make a bigger square ending at (i, j),
                        // we need a square on:
                        //
                        // 1. Top       -> dp[i-1][j]
                        // 2. Left      -> dp[i][j-1]
                        // 3. Diagonal  -> dp[i-1][j-1]
                        //
                        // We take the minimum because the smallest
                        // of these three limits the size of our square.
                        dp[i][j] = 1 + min({
                            dp[i - 1][j - 1],  // diagonal
                            dp[i - 1][j],     // top
                            dp[i][j - 1]      // left
                        });
                    }
                }

                // Update the maximum side length
                maxi = max(maxi, dp[i][j]);
            }
        }

        // maxi is the side length.
        // Area of a square = side × side
        return maxi * maxi;
    }
};