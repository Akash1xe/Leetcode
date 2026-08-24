class Solution {
public:
    int solve(int mask, int n, int k, vector<int>& prereq, vector<int>& dp) {

        // All courses are completed
        if (mask == (1 << n) - 1)
            return 0;

        // Already solved
        if (dp[mask] != -1)
            return dp[mask];

        // Find all courses that can currently be taken
        int available = 0;

        for (int i = 0; i < n; i++) {

            // Already completed
            if (mask & (1 << i))
                continue;

            // Check whether all prerequisites are completed
            if ((mask & prereq[i]) == prereq[i]) {
                available |= (1 << i);
            }
        }

        int ans = INT_MAX;

        // If we can take all available courses,
        // there is no need to try smaller subsets.
        if (__builtin_popcount(available) <= k) {

            ans = 1 + solve(mask | available, n, k, prereq, dp);

        } else {

            // Try every subset of available courses
            // that contains at most k courses.
            for (int sub = available; sub; sub = (sub - 1) & available) {

                // We can take at most k courses
                if (__builtin_popcount(sub) > k)
                    continue;

                // Take these courses this semester
                ans = min(ans, 1 + solve(mask | sub, n, k, prereq, dp));
            }
        }

        return dp[mask] = ans;
    }

    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {

        // Local variables
        vector<int> prereq(n, 0);

        // Build prerequisite bitmask
        for (auto& r : relations) {

            int u = r[0] - 1;
            int v = r[1] - 1;

            // u must be completed before v
            prereq[v] |= (1 << u);
        }

        // Local DP vector
        vector<int> dp(1 << n, -1);

        // Start recursion
        return solve(0, n, k, prereq, dp);
    }
};