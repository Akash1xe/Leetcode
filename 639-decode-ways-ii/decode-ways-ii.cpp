class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long solve(int i, string &s, vector<long long> &dp) {
        int n = s.length();

        // Reached the end: one valid decoding
        if (i == n)
            return 1;

        // Already calculated
        if (dp[i] != -1)
            return dp[i];

        long long ways = 0;

        // ------------------------------------------------
        // CASE 1: Decode one character
        // ------------------------------------------------
        if (s[i] == '*') {

            // '*' can be 1 to 9
            ways += 9LL * solve(i + 1, s, dp);
        }
        else if (s[i] != '0') {

            // Any digit 1-9 can be decoded
            ways += solve(i + 1, s, dp);
        }

        // ------------------------------------------------
        // CASE 2: Decode two characters
        // ------------------------------------------------
        if (i + 1 < n) {

            char a = s[i];
            char b = s[i + 1];

            long long pairWays = 0;

            // ** -> 15 valid combinations
            if (a == '*' && b == '*') {

                pairWays = 15;
            }

            // * followed by a normal digit
            else if (a == '*') {

                if (b >= '0' && b <= '6')
                    pairWays = 2;
                else
                    pairWays = 1;
            }

            // normal digit followed by *
            else if (b == '*') {

                if (a == '1')
                    pairWays = 9;
                else if (a == '2')
                    pairWays = 6;
            }

            // both are normal digits
            else {

                int num = (a - '0') * 10 + (b - '0');

                if (num >= 10 && num <= 26)
                    pairWays = 1;
            }

            ways += pairWays * solve(i + 2, s, dp);
        }

        return dp[i] = ways % MOD;
    }

    int numDecodings(string s) {

        int n = s.length();

        vector<long long> dp(n, -1);

        return solve(0, s, dp);
    }
};