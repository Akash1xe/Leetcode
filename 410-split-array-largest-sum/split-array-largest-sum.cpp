class Solution {
public:

    // Check whether we can split nums into at most k subarrays
    // such that no subarray sum exceeds 'limit'.
    bool canSplit(vector<int>& nums, int k, long long limit) {

        int parts = 1;
        long long currentSum = 0;

        for (int num : nums) {

            // Adding num would exceed our allowed maximum sum.
            if (currentSum + num > limit) {
                parts++;
                currentSum = num;

                // We need more than k subarrays,
                // so this limit is too small.
                if (parts > k)
                    return false;
            }
            else {
                currentSum += num;
            }
        }

        return true;
    }


    int splitArray(vector<int>& nums, int k) {

        // Minimum possible answer:
        // At least the largest element must fit in some subarray.
        long long low = *max_element(nums.begin(), nums.end());

        // Maximum possible answer:
        // Put everything in one subarray.
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        long long ans = high;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {

                // mid works.
                // Try to find a smaller maximum subarray sum.
                ans = mid;
                high = mid - 1;
            }
            else {

                // mid is too small.
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};