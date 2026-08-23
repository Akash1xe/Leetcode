class Solution {
public:

    int lenLongestFibSubseq(vector<int>& arr) {

        int n = arr.size();

        // dp[prev][curr] = number of elements we can
        // add after the pair (prev, curr).
        vector<vector<int>> dp(
            n,
            vector<int>(n, 0)
        );

        int ans = 0;

        // Process curr from right to left because
        // dp[prev][curr] depends on dp[curr][next].
        for (int curr = n - 2; curr >= 1; curr--) {

            // prev must always be before curr.
            for (int prev = curr - 1;
                 prev >= 0;
                 prev--) {

                // For a Fibonacci-like sequence:
                // arr[next] = arr[prev] + arr[curr].
                int nextValue =
                    arr[prev] + arr[curr];

                // Search for the required next element
                // after curr.
                for (int next = curr + 1;
                     next < n;
                     next++) {

                    // If the required next value exists,
                    // extend the sequence from (curr, next).
                    if (arr[next] == nextValue) {

                        // 1 = the newly found next element.
                        // dp[curr][next] = further elements
                        // that can be added after it.
                        dp[prev][curr] =
                            1 + dp[curr][next];
                    }
                }

                // Start with the first two elements:
                // arr[prev] and arr[curr].
                //
                // dp[prev][curr] = additional elements.
                // Therefore total length = 2 + dp[prev][curr].
                ans = max(
                    ans,
                    2 + dp[prev][curr]
                );
            }
        }

        // A valid Fibonacci-like subsequence needs
        // at least 3 elements.
        return ans >= 3 ? ans : 0;
    }
};