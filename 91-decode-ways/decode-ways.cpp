// Approach-2 (Bottom Up Way-1)
// T.C : O(n)
// S.C : O(n)

class Solution {
public:
    int bottom_up_1(string &s, int n) {

        // dp[i] = number of ways to decode
        // the substring starting from index i
        vector<int> dp(n + 1, 0);

        // Base case:
        // If we reach the end of the string,
        // there is exactly 1 way to decode it.
        dp[n] = 1;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // '0' cannot be decoded by itself
            if (s[i] == '0') {
                dp[i] = 0;
            }
            else {

                // Take s[i] as a single digit
                dp[i] = dp[i + 1];

                // Take s[i] and s[i+1] together as a
                // valid two-digit number
                if (i < n - 1 &&
                    (s[i] == '1' ||
                    (s[i] == '2' && s[i + 1] < '7'))) {

                    dp[i] += dp[i + 2];
                }
            }
        }

        // dp[0] = number of ways to decode the entire string
        return dp[0];
    }

    int numDecodings(string &s) {
        int n = s.length();

        return bottom_up_1(s, n);
    }
};