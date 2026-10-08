class Solution {
public:

    bool isPalindrome(string &s, int i, int j) {

        while (i < j) {

            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    int f(int i,
          string &s,
          vector<int>& dp) {

        int n = s.size();

        // Base case
        if (i == n) {
            return -1;
        }

        // Already calculated
        if (dp[i] != -2) {
            return dp[i];
        }

        int minCuts = INT_MAX;

        for (int j = i; j < n; j++) {

            if (isPalindrome(s, i, j)) {

                int cuts =
                    1 + f(j + 1, s, dp);

                minCuts =
                    min(minCuts, cuts);
            }
        }

        return dp[i] = minCuts;
    }

    int minCut(string s) {

        int n = s.size();

        vector<int> dp(n, -2);

        return f(0, s, dp);
    }
};