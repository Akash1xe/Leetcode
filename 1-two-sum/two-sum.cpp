#include <bits/stdc++.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {

            int need = target - nums[i];

            if (mpp.find(need) != mpp.end()) {
                cout << i << mpp[need] << endl;

                return {mpp[need],i} ;
            }

            mpp[nums[i]] = i;
        }

        return {};
    }
};