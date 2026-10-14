class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;

        int left = 0;
        int right = 0;

        int n = nums.size() - 1;
        int maxSum = INT_MIN;

        while (right <= n) {
            sum += nums[right];

            if (right - left + 1 > k) {

                sum -= nums[left];
                left++;
            }

            if (right - left + 1 == k) {
                maxSum = max(maxSum, sum);
            }

            right++;
        }

        return (double)maxSum / k;
    }
};