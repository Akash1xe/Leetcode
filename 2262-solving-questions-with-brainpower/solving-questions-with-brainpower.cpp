class Solution {
public:

    long long solve(int i, vector<vector<int>>& questions,
                    vector<long long>& dp) {

        // Base case
        if (i >= questions.size())
            return 0;

        // Already calculated
        if (dp[i] != -1)
            return dp[i];

        // Choice 1: Solve current question
        long long take =
            questions[i][0] +
            solve(i + questions[i][1] + 1, questions, dp);

        // Choice 2: Skip current question
        long long skip =
            solve(i + 1, questions, dp);

        // Store and return the best answer
        return dp[i] = max(take, skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {

        int n = questions.size();

        // dp[i] = maximum points starting from question i
        vector<long long> dp(n, -1);

        return solve(0, questions, dp);
    }
};