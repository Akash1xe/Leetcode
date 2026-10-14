
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size() - 1;

        long long maxSum = LLONG_MIN;
        long long sum = 0;

        int left = 0;
        int right = 0;

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
