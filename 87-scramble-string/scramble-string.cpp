class Solution {
public:
    int dp[31][31][31];

    bool solve(int i, int j, int len, string& s1, string& s2) {

        if (len == 1)
            return s1[i] == s2[j];

        if (dp[i][j][len] != -1)
            return dp[i][j][len];

        // Check if both parts are already equal
        bool same = true;

        for (int k = 0; k < len; k++) {
            if (s1[i + k] != s2[j + k]) {
                same = false;
                break;
            }
        }

        if (same)
            return dp[i][j][len] = true;

        for (int cut = 1; cut < len; cut++) {

            // Case 1: No Swap
            bool noSwap = solve(i, j, cut, s1, s2) &&
                          solve(i + cut, j + cut, len - cut, s1, s2);

            if (noSwap)
                return dp[i][j][len] = true;

            // Case 2: Swap
            bool swap = solve(i, j + len - cut, cut, s1, s2) &&

                        solve(i + cut, j, len - cut, s1, s2);

            if (swap)
                return dp[i][j][len] = true;
        }

        return dp[i][j][len] = false;
    }

    bool isScramble(string s1, string s2) {

        if (s1.length() != s2.length())
            return false;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, s1.length(), s1, s2);
    }
};