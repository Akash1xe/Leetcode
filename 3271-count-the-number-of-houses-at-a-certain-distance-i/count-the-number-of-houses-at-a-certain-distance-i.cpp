class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {

        // grid[i][j] = shortest distance from house i to house j
        // Initialize with a very large value (acts as INF)
        vector<vector<int>> grid(n + 1, vector<int>(n + 1, 100000));

        // Distance from a house to itself is 0
        for (int i = 1; i <= n; i++) {
            grid[i][i] = 0;
        }

        // Build the line graph:
        // 1-2-3-...-n
        for (int j = 1; j < n; j++) {
            grid[j][j + 1] = 1;
            grid[j + 1][j] = 1;
        }

        // Add the extra bidirectional road between x and y
        grid[x][y] = 1;
        grid[y][x] = 1;

        // Floyd-Warshall Algorithm
        // Try every node as an intermediate (via) node
        for (int via = 1; via <= n; via++) {

            // Source node
            for (int i = 1; i <= n; i++) {

                // Destination node
                for (int j = 1; j <= n; j++) {

                    // If travelling through 'via' gives a shorter path,
                    // update the shortest distance.
                    grid[i][j] = min(grid[i][j],
                                     grid[i][via] + grid[via][j]);
                }
            }
        }

        // result[d - 1] = number of ordered pairs
        // having shortest distance exactly d
        vector<int> result(n);

        // Check every ordered pair of houses
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                // Ignore same house
                if (i != j) {

                    // Shortest distance between i and j
                    int val = grid[i][j];

                    // Increase the count for this distance
                    result[val - 1]++;
                }
            }
        }

        return result;
    }
};