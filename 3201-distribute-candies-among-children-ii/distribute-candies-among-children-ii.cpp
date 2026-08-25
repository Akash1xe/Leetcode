class Solution {
public:

    // Returns the number of ways to choose 2 items from x items.
    // C(x, 2) = x * (x - 1) / 2
    // If x < 2, choosing 2 items is impossible.
    long long C(long long x) {
        if (x < 2)
            return 0;

        return x * (x - 1) / 2;
    }

    long long distributeCandies(int n, int limit) {

        // We have 3 children and each child can receive at most 'limit'.
        // Therefore, the maximum total number of candies is 3 * limit.
        // If n is greater than this, no valid distribution exists.
        if (n > 3LL * limit)
            return 0;

        // Inclusion-Exclusion:
        //
        // Total solutions without any upper limit:
        // x1 + x2 + x3 = n
        // => C(n + 2, 2)
        //
        // Subtract cases where at least one child receives
        // more than 'limit' candies:
        // 3 * C(n - limit + 1, 2)
        //
        // But cases where two children exceed the limit
        // were subtracted twice, so add them back:
        // 3 * C(n - 2 * limit, 2)
        //
        // Three children exceeding the limit is impossible here
        // after the maximum-limit check.
        return C(n + 2)
             - 3LL * C(n - limit + 1)
             + 3LL * C(n - 2LL * limit);
    }
};