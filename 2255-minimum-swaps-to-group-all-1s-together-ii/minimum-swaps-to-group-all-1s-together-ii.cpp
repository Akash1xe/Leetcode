class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Count total number of 1s
        int countOnes = 0;

        for (int x : nums) {
            countOnes += x;
        }

        // Sliding window
        int i = 0;
        int j = 0;

        // Number of 1s in the current window
        int currCount = 0;

        // Maximum number of 1s found in any window
        int maxCount = 0;

        // Traverse 2*n elements to handle the circular array
        while (j < 2 * n) {

            // Add the current element to the window
            // j % n makes the array circular
            if (nums[j % n] == 1) {
                currCount++;
            }

            // Window size should be equal to total number of 1s
            if (j - i + 1 > countOnes) {

                // Remove the leftmost element from the window
                // Since nums[i % n] is either 0 or 1,
                // we can directly subtract it
                currCount -= nums[i % n];

                i++;
            }

            // Store the maximum number of 1s
            // present in any window of size countOnes
            maxCount = max(maxCount, currCount);

            j++;
        }

        // Number of zeros in the best window
        // = swaps required
        return countOnes - maxCount;
    }
};