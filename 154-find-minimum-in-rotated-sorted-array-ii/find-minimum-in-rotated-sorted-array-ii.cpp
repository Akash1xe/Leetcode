class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            // All three are same -> duplicates on both sides
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }

            // Mid is greater than high
            // Minimum must be on right side
            else if (nums[mid] > nums[high]) {
                low = mid + 1;
            }

            // Mid is smaller than or equal to high
            // Minimum is mid or on left side
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};