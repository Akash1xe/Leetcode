class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {

        // answer[i] = number of ordered pairs having distance (i + 1)
        vector<int> ans(n, 0);

        // Try every ordered pair (i, j)
        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= n; j++) {

                // Ignore same house
                if (i == j)
                    continue;

                // Option 1: Walk directly on the line
                int direct = abs(i - j);

                // Option 2: Use extra road x -> y
                int path1 = abs(i - x) + 1 + abs(j - y);

                // Option 3: Use extra road y -> x
                int path2 = abs(i - y) + 1 + abs(j - x);

                // Shortest possible distance
                int dist = min({direct, path1, path2});

                // Store frequency
                ans[dist - 1]++;
            }
        }

        return ans;
    }
};