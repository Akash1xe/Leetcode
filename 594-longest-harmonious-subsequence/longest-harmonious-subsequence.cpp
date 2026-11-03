class Solution {
public:
    int findLHS(vector<int>& nums) {

        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        int ans = 0;

        for (auto it : mp) {
            if (mp.find(it.first + 1) != mp.end()) {
                ans = max(ans, it.second + mp[it.first + 1]);
            }
        }

        return ans;
    }
};