class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> nums;
        int fact = 1;

        // Store numbers from 1 to n
        for (int i = 1; i < n; i++) {
            fact *= i;
            nums.push_back(i);
        }

        nums.push_back(n);

        // Convert k to 0-based indexing
        k--;

        string ans = "";

        while (true) {

            // Find which number should come at current position
            int index = k / fact;

            ans += to_string(nums[index]);

            // Remove the used number
            nums.erase(nums.begin() + index);

            // If no numbers are left
            if (nums.empty()) {
                break;
            }

            // Remaining permutation number
            k = k % fact;

            // Update factorial for next position
            fact = fact / nums.size();
        }

        return ans;
    }
};