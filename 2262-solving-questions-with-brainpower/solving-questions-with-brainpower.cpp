class Solution {
public:

    long long mostPoints(vector<vector<int>>& questions) {

        int n = questions.size();

        // dp[i] = maximum points we can get
        // starting from question i
        vector<long long> dp(n + 1, 0);

        // Fill from right to left
        for (int i = n - 1; i >= 0; i--) {

            int points = questions[i][0];
            int brainpower = questions[i][1];

            // Choice 1: Solve current question
            int next = i + brainpower + 1;

            long long take = points;

            if (next < n) {
                take += dp[next];
            }

            // Choice 2: Skip current question
            long long skip = dp[i + 1];

            // Take the better choice
            dp[i] = max(take, skip);
        }

        return dp[0];
    }
};