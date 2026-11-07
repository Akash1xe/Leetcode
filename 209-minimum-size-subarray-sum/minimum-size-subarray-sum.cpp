class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0;          // Left pointer of the sliding window
        int ans = INT_MAX;     // Stores the minimum valid window length
        int sum = 0;           // Current window sum

        // Expand the window by moving the right pointer
        for (int right = 0; right < nums.size(); right++) {

            // Include the current element in the window
            sum += nums[right];

            // If the current window sum is at least the target,
            // try to shrink the window from the left
            while (sum >= target) {

                // Update the minimum window length
                ans = min(ans, right - left + 1);

                // Remove the leftmost element from the window
                sum -= nums[left];

                // Move the left pointer forward
                left++;
            }
        }

        // If no valid subarray was found, return 0
        return ans == INT_MAX ? 0 : ans;
    }
};

/*
========================================
Intuition
========================================

We need to find the smallest contiguous subarray whose sum is
greater than or equal to the target.

Since all numbers are positive:
- Expanding the window (moving right) always increases the sum.
- Shrinking the window (moving left) always decreases the sum.

This property allows us to use the Sliding Window technique.

Algorithm:
1. Keep expanding the window by moving the right pointer.
2. Add each element to the current window sum.
3. As soon as the sum becomes >= target:
      - Update the minimum length.
      - Shrink the window from the left as much as possible
        while keeping the sum >= target.
4. Continue until the right pointer reaches the end.

This guarantees that every possible valid window is checked exactly once.

Time Complexity : O(n)
- Each element is added to the window once and removed once.

Space Complexity : O(1)
- Only a few extra variables are used.
*/