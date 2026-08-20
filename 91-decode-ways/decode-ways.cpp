class Solution {
public:
    int t[101];

    // Number of ways to decode string starting from index i
    int solve(int i, string &s, int &n) {

        // Already calculated
        if(t[i] != -1) {
            return t[i];
        }

        // Reached end successfully
        if(i == n) {
            return t[i] = 1;
        }

        // 0 cannot be decoded alone
        if(s[i] == '0') {
            return t[i] = 0;
        }

        // Choice 1: take one digit
        int result = solve(i + 1, s, n);

        // Choice 2: take two digits
        if(i + 1 < n) {

            // Valid two-digit number:
            // 10-19 OR 20-26
            if(s[i] == '1' ||
              (s[i] == '2' && s[i + 1] <= '6')) {

                result += solve(i + 2, s, n);
            }
        }

        return t[i] = result;
    }

    int numDecodings(string s) {

        int n = s.length();

        memset(t, -1, sizeof(t));

        return solve(0, s, n);
    }
};