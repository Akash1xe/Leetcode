class Solution {
public:
    void solve(int start, vector<int>& nums,
               vector<int>& curr,
               vector<vector<int>>& ans) {

        // Every current subset is valid
        ans.push_back(curr);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            // Take nums[i]
            curr.push_back(nums[i]);

            solve(i + 1, nums, curr, ans);

            // Backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Important: bring duplicates together
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, nums, curr, ans);

        return ans;
    }
};