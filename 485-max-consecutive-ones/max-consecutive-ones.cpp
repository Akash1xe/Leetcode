#include <bits/stdc++.h>

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int cnt = 0;
        int maxCount = 0;

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if (nums[i] == 1) {
                cnt++;
            } else {
                cnt = 0;
            }

            maxCount = max(maxCount, cnt);
        }

        return maxCount ;
    }
};