class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();

        vector<vector<int>> jobs(n, vector<int>(3));

        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        // Sort by start time
        sort(jobs.begin(), jobs.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        // DP array inside main function
        vector<int> dp(n, -1);

        // Recursive function
        function<int(int)> solve = [&](int i) {

            if (i >= n)
                return 0;

            if (dp[i] != -1)
                return dp[i];

            // Find next non-overlapping job
            int l = i + 1;
            int r = n - 1;
            int next = n;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (jobs[mid][0] >= jobs[i][1]) {
                    next = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            // Take current job
            int take = jobs[i][2] + solve(next);

            // Skip current job
            int skip = solve(i + 1);

            return dp[i] = max(take, skip);
        };

        return solve(0);
    }
};