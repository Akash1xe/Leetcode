class Solution {
public:

    // Check if there are at least k pairs
    // having distance <= dist
    bool possible(vector<int>& nums, int k, int dist) {

        int left = 0;
        long long count = 0;

        // Right pointer will act as the second element of the pair
        for (int right = 0; right < nums.size(); right++) {

            // If current distance is greater than dist,
            // move left forward until the window becomes valid
            while (nums[right] - nums[left] > dist) {
                left++;
            }

            // All elements from left to right - 1
            // can form a valid pair with nums[right]
            //
            // Number of valid pairs ending at right:
            // right - left
            count += right - left;
        }

        // If we have at least k pairs with distance <= dist,
        // then dist can be a possible answer
        return count >= k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {

        // Sort so that pair distance can be calculated as:
        // nums[right] - nums[left]
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Minimum possible pair distance is 0
        int low = 0;

        // Maximum possible pair distance is:
        // largest element - smallest element
        int high = nums[n - 1] - nums[0];

        // Binary search on the answer
        //
        // We are searching for the smallest distance
        // for which at least k pairs have distance <= that distance
        while (low <= high) {

            int mid = low + (high - low) / 2;

            // If at least k pairs have distance <= mid,
            // mid can be the answer.
            // But try to find an even smaller valid distance.
            if (possible(nums, k, mid)) {
                high = mid-1;
            }

            // If fewer than k pairs have distance <= mid,
            // then the kth smallest distance must be greater than mid.
            else {
                low = mid + 1;
            }
        }

        // low == high gives the first distance
        // for which count of pairs >= k
        return low;
    }
};