class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {

        unordered_map<int, int> dp;

        int ans = 1;

        for (int x : arr) {

            // We need a previous value:
            // x - difference
            int prev = x - difference;

            // If prev exists, extend its subsequence.
            // Otherwise, start a new subsequence with x.
            dp[x] = dp[prev] + 1;

            ans = max(ans, dp[x]);
        }

        return ans;
    }
};