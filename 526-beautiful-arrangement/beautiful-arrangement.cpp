class Solution {
public:

    int func(int ind, int n, vector<int>& used) {

        // We successfully filled positions 1...n
        if (ind > n) {
            return 1;
        }

        int count = 0;

        // Try placing every number from 1 to n
        for (int i = 1; i <= n; i++) {

            // Number i should not already be used
            // and it must satisfy the beautiful condition
            if (!used[i] && (i % ind == 0 || ind % i == 0)) {

                // Choose i for current position
                used[i] = 1;

                count += func(ind + 1, n, used);

                // Backtrack
                used[i] = 0;
            }
        }

        return count;
    }

    int countArrangement(int n) {

        vector<int> used(n + 1, 0);

        // Positions start from 1, not 0
        return func(1, n, used);
    }
};