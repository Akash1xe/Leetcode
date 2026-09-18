class Solution {
public:

    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums, vector<int>& curr) {

        // Base case
        if (idx == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // Choice 1: Don't take nums[idx]
        solve(idx + 1, nums, curr);

        // Choice 2: Take nums[idx]
        curr.push_back(nums[idx]);

        solve(idx + 1, nums, curr);

        // Backtrack
        curr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> curr;

        solve(0, nums, curr);

        return ans;
    }
};