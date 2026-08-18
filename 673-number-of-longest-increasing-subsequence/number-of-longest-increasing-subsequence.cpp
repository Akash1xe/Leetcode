class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size(); 
        // Get the size of the input array

        vector<int> dp(n, 1);   
        // dp[i] will store the length of the Longest Increasing Subsequence
        // that ends exactly at index i
        // Initialize with 1 because every single element itself is a LIS of length 1

        vector<int> cnt(n, 1);  
        // cnt[i] will store how many LIS of length dp[i] end at index i
        // Initialize with 1 because each element alone forms one subsequence

        int maxi = 1;           
        // This will store the maximum LIS length found so far

        for (int i = 0; i < n; i++) {
            // Outer loop: we try to compute LIS ending at index i

            for (int prev = 0; prev < i; prev++) {
                // Inner loop: check all previous elements before i

                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i]) {
                    // Condition 1:
                    // nums[prev] < nums[i] → increasing condition
                    // 1 + dp[prev] > dp[i] → found a strictly longer LIS ending at i

                    dp[i] = 1 + dp[prev];     
                    // Update LIS length at i

                    cnt[i] = cnt[prev];       
                    // Since we found a better LIS,
                    // we take the count from prev
                    // (because all those subsequences can now extend to i)
                }
                else if (nums[prev] < nums[i] && 1 + dp[prev] == dp[i]) {
                    // Condition 2:
                    // Found another subsequence of same maximum length ending at i

                    cnt[i] += cnt[prev];      
                    // Add the number of ways from prev
                    // because we found another LIS of same length
                }
            }

            maxi = max(maxi, dp[i]);  
            // Update overall maximum LIS length
        }

        int number_of_LIS = 0;  
        // This will store total number of LIS of maximum length

        for (int i = 0; i < n; i++) {
            // Traverse all indices

            if (dp[i] == maxi) {
                // If this index contributes to a maximum length LIS

                number_of_LIS += cnt[i];  
                // Add its count to final answer
            }
        }

        return number_of_LIS; 
        // Return total number of longest increasing subsequences
    }
};