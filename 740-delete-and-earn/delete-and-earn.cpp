class Solution {
public:
    int solve(int ind, vector<int>& points,vector<int>& dp) {
        if (ind < 0) {
            return 0;
        }

        if (ind == 0) {
            return points[0];
        }

        if(dp[ind]!=-1){
            return dp[ind];
        }

        int pick = points[ind] + solve(ind - 2, points,dp);

        int not_pick = solve(ind - 1, points,dp);

        return dp[ind] = max(pick, not_pick);
    }

    int deleteAndEarn(vector<int>& nums) {

        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> points(maxi + 1, 0);

        for (int x : nums) {
            points[x] += x;
        }

        vector<int>dp(maxi+1,-1);

        return solve(maxi, points,dp);
    }
};