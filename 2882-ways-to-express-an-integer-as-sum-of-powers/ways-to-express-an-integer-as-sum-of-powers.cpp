class Solution {
public:
    int M = 1e9 + 7;

    int getPower(int num, int x, int n) {
        long long ans = 1;

        for(int i = 0; i < x; i++) {
            ans *= num;

            if(ans > n)
                return n + 1;
        }

        return ans;
    }

    int numberOfWays(int n, int x) {

        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        for(int num = 1; num <= n + 1; num++) {
            dp[0][num] = 1;
        }

        for(int curr = 1; curr <= n; curr++) {

            for(int num = n; num >= 1; num--) {

                int power = getPower(num, x, n);

                int take = 0;

                if(power <= curr) {
                    take = dp[curr - power][num + 1];
                }

                int skip = dp[curr][num + 1];

                dp[curr][num] = (take + skip) % M;
            }
        }

        return dp[n][1];
    }
};