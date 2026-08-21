// Approach-2: Bottom-Up DP
// T.C : O(n)
// S.C : O(n)

class Solution {
public:
    int M = 1e9 + 7;

    int checkRecord(int n) {

        // dp[i][A][L]
        // i = number of days considered
        // A = number of absences used (0 or 1)
        // L = number of consecutive late days (0, 1, or 2)
        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(3, 0))
        );

        // Base Case:
        // If there are 0 days, there is exactly 1 valid way:
        // choose nothing.
        for (int A = 0; A <= 1; A++) {
            for (int L = 0; L <= 2; L++) {
                dp[0][A][L] = 1;
            }
        }

        // Build the DP table from 1 day to n days
        for (int i = 1; i <= n; i++) {

            // Try every possible number of absences
            for (int A = 0; A <= 1; A++) {

                // Try every possible number of consecutive L's
                for (int L = 0; L <= 2; L++) {

                    long long result = 0;

                    // Choice 1: Present (P)
                    // P breaks the consecutive L streak,
                    // so L becomes 0.
                    result += dp[i - 1][A][0];

                    // Choice 2: Late (L)
                    // We can add L only if we currently have
                    // fewer than 2 consecutive L's.
                    if (L < 2) {
                        result += dp[i - 1][A][L + 1];
                    }

                    // Choice 3: Absent (A)
                    // We can add A only if we have used
                    // 0 absences so far.
                    if (A == 0) {
                        result += dp[i - 1][A + 1][0];
                    }

                    // Store the answer for this state
                    dp[i][A][L] = result % M;
                }
            }
        }

        // Start with n days,
        // 0 absences used,
        // 0 consecutive late days.
        return dp[n][0][0];
    }
};