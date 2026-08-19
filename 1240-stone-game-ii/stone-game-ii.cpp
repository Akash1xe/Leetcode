class Solution {
public:

    int n;

    int solve(vector<int>& piles, vector<vector<vector<int>>>& t,
              int person, int i, int M) {

        if (i >= n)
            return 0;

        if (t[person][i][M] != -1)
            return t[person][i][M];

        int result = (person == 1) ? -1 : INT_MAX;

        int stones = 0;

        for (int x = 1; x <= min(2 * M, n - i); x++) {

            stones += piles[i + x - 1];

            if (person == 1) {
                // Alice wants to maximize her stones
                result = max(
                    result,
                    stones + solve(piles, t, 0, i + x, max(M, x))
                );
            }
            else {
                // Bob wants to minimize Alice's stones
                result = min(
                    result,
                    solve(piles, t, 1, i + x, max(M, x))
                );
            }
        }

        return t[person][i][M] = result;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        // DP: t[person][i][M]
        vector<vector<vector<int>>> t(
            2,
            vector<vector<int>>(n + 1, vector<int>(n + 1, -1))
        );

        return solve(piles, t, 1, 0, 1);
    }
};