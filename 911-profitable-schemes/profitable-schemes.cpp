class Solution {
public:
    int thresholdProfit;
    int N;
    const int MOD = 1e9 + 7;

    int t[101][101][101];

    int solve(int i, int p, int people,
              vector<int>& group, vector<int>& profit) {

        // Too many people
        if (people > N)
            return 0;

        // All crimes considered
        if (i == group.size()) {
            if (p >= thresholdProfit)
                return 1;

            return 0;
        }

        // Already calculated
        if (t[i][p][people] != -1)
            return t[i][p][people];

        // Don't take current crime
        long long not_taken =
            solve(i + 1, p, people, group, profit);

        // Take current crime
        long long taken =
            solve(i + 1,
                  min(thresholdProfit, p + profit[i]),
                  people + group[i],
                  group, profit);

        // Store answer
        return t[i][p][people] =
            (taken + not_taken) % MOD;
    }

    int profitableSchemes(int n, int minProfit,
                          vector<int>& group,
                          vector<int>& profit) {

        N = n;
        thresholdProfit = minProfit;

        memset(t, -1, sizeof(t));

        return solve(0, 0, 0, group, profit);
    }
};