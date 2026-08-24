class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0;

        // Total number of 1s
        for (int x : nums) {
            ones += x;
        }

        if (ones <= 1) return 0;

        int zeros = 0;
        int ans = INT_MAX;

        // Circular array: window size = number of 1s
        for (int i = 0; i < nums.size() + ones - 1; i++) {
            int idx = i % nums.size();

            if (nums[idx] == 0)
                zeros++;

            // Maintain window size = ones
            if (i >= ones) {
                int left = (i - ones) % nums.size();

                if (nums[left] == 0)
                    zeros--;
            }

            // Once window has size `ones`
            if (i >= ones - 1) {
                ans = min(ans, zeros);
            }
        }

        return ans;
    }
};