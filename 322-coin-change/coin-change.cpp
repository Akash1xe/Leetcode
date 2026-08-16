class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int target = 0; target <= amount; target++) {

            if (target % coins[0] == 0) {
                dp[0][target] = target / coins[0];
            } else {
                dp[0][target] = 1e9;
            }
        }

        for (int ind = 1; ind < n; ind++) {

            for (int target = 0; target <= amount; target++) {

                int notTake = dp[ind - 1][target];

                int take = 1e9;

                if (coins[ind] <= target) {

                    take = 1 + dp[ind][target - coins[ind]];
                }

                dp[ind][target] = min(notTake, take);
            }
        }

        int ans = dp[n - 1][amount];

        if (ans >= 1e9)
            return -1;

        return ans;
    }
};

/*
===============================================================
INTUITION
===============================================================

We want to find the MINIMUM number of coins required to make
the given 'amount'.

For every coin, we have TWO choices:

        1. DON'T TAKE the coin
        2. TAKE the coin


Example:

coins = [1, 2, 5]
amount = 11


Suppose we are currently looking at coin = 5.

We ask:

        Should I take 5?
        OR
        Should I skip 5?


---------------------------------------------------------------
1. NOT TAKE
---------------------------------------------------------------

If we don't take the current coin, we move to the previous
coin.

Therefore:

        notTake = dp[ind - 1][target]


This means:

"Find the answer without using the current coin."


---------------------------------------------------------------
2. TAKE
---------------------------------------------------------------

If we take the current coin:

        +1 coin is used

and the remaining amount becomes:

        target - coins[ind]


But this is an UNBOUNDED coin change problem.

That means we can use the SAME coin again.

Therefore we DO NOT move to ind - 1.

We stay at the same index:

        take = 1 + dp[ind][target - coins[ind]]


This is the MOST IMPORTANT part of this problem.


---------------------------------------------------------------
WHY dp[ind] FOR TAKE?
---------------------------------------------------------------

Suppose:

coins = [1, 2, 5]

current coin = 5
target = 15

We can do:

        15 -> take 5
        10 -> take 5
         5 -> take 5
         0


So we use coin 5 three times.

Therefore:

        dp[ind][15]
            |
            +-- dp[ind][10]
                    |
                    +-- dp[ind][5]
                            |
                            +-- dp[ind][0]


We stay at the SAME index because the coin can be reused.


---------------------------------------------------------------
FINAL FORMULA
---------------------------------------------------------------

notTake = dp[ind - 1][target]

take = 1 + dp[ind][target - coins[ind]]

answer:

dp[ind][target] = min(notTake, take)


---------------------------------------------------------------
HOW RECURSION BECOMES TABULATION
---------------------------------------------------------------

Recursive:

        Change(ind - 1, target)

becomes:

        dp[ind - 1][target]


Recursive:

        1 + Change(ind, target - coins[ind])

becomes:

        1 + dp[ind][target - coins[ind]]


So the main conversion is:

        RECURSION
             ↓
        DP TABLE


---------------------------------------------------------------
WHAT DOES dp[ind][target] MEAN?
---------------------------------------------------------------

For example:

        dp[2][11]

if:

        coins = [1, 2, 5]

then dp[2][11] means:

"Minimum number of coins required to make amount 11
using coins [1, 2, 5]."


The final answer is:

        dp[n-1][amount]


---------------------------------------------------------------
TIME AND SPACE COMPLEXITY
---------------------------------------------------------------

Time Complexity:

        O(n * amount)

because we calculate every cell once.


Space Complexity:

        O(n * amount)

because we create a 2D DP table.


===============================================================
*/