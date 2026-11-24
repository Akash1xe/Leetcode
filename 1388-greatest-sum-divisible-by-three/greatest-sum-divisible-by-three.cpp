// Approach-2 - Recursion Memoization
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
    int solve(int i, int remainder, vector<int>& nums, vector<vector<int>>& t) {
        if (i >= nums.size()) {
            if (remainder == 0)
                return 0;

            return INT_MIN;
        }
        if (t[i][remainder] != -1)
            return t[i][remainder];

        // Pick the current number
        int pick = nums[i] + solve(i + 1, (remainder + nums[i]) % 3, nums, t);

        // Skip the current number
        int notPick = solve(i + 1, remainder, nums, t);

        return t[i][remainder] = max(pick, notPick);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> t(n, vector<int>(3, -1));
        return solve(0, 0, nums, t);
    }
};