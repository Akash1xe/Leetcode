class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeroCount = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Add current element to the window
            if (nums[right] == 0) {
                zeroCount++;
            }

            // Window becomes invalid if zeros > k
            while (zeroCount > k) {

                // Remove nums[left] from the window
                if (nums[left] == 0) {
                    zeroCount--;
                }

                left++;
            }

            // Current window has at most k zeros
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};