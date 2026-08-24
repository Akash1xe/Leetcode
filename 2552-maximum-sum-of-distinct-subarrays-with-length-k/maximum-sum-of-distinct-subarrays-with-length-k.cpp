class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        // Stores the frequency of each element in the current window
        unordered_map<int, int> mp;

        // Sum of elements in the current window
        long long sum = 0;

        // Maximum sum found among valid windows
        long long ans = 0;

        // Left pointer of the sliding window
        int i = 0;

        // Right pointer expands the window
        for (int j = 0; j < nums.size(); j++) {

            // Add the current element to the window
            sum += nums[j];
            mp[nums[j]]++;

            // If window size becomes greater than k,
            // remove elements from the left
            if (j - i + 1 > k) {

                // Remove nums[i] from the window sum
                sum -= nums[i];

                // Decrease its frequency
                mp[nums[i]]--;

                // If its frequency becomes 0,
                // remove it completely from the map
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }

                // Move the left pointer forward
                i++;
            }

            // Window size is exactly k
            // mp.size() == k means all k elements are distinct
            if (j - i + 1 == k && mp.size() == k) {

                // Update maximum sum
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};