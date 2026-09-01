class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if (k <= 1)
            return 0;

        int left = 0;
        long long product = 1;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Include right
            product *= nums[right];

            // Invalid window
            while (product >= k) {

                product /= nums[left];

                left++;
            }

            // Number of valid subarrays
            // ending at right
            count += right - left + 1;
        }

        return count;
    }
};