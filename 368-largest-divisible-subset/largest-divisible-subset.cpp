class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();   // Get the total number of elements
        
        if(n == 0) return {};  // If array is empty, return empty result
        
        sort(nums.begin(), nums.end());   
        // Sort the array so that smaller numbers come first.
        // This ensures that when we check divisibility,
        // we always try to divide a bigger number by a smaller one.

        vector<int> dp(n, 1);  
        // dp[i] = length of largest divisible subset ending at index i
        // Initially every number itself is a subset of length 1
        
        vector<int> hash(n);   
        // hash[i] will store the previous index of the element
        // in the divisible subset chain (used for reconstruction)
        
        int maxi = 1;         
        // Stores maximum length of divisible subset found so far
        
        int lastIndex = 0;    
        // Stores index where maximum subset ends
        
        for(int i = 0; i < n; i++) {
            hash[i] = i;      
            // Initially, every element points to itself
            // (means subset contains only that element)
        }
        
        // Start building DP
        for(int i = 0; i < n; i++) {
            
            // Check all previous elements
            for(int prev = 0; prev < i; prev++) {
                
                // If current number is divisible by previous number
                // AND including prev gives a longer subset
                if(nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]) {
                    
                    dp[i] = 1 + dp[prev];  
                    // Update dp[i] because we found a longer chain
                    
                    hash[i] = prev;       
                    // Store previous index to reconstruct later
                }
            }
            
            // Update global maximum subset length
            if(dp[i] > maxi) {
                maxi = dp[i];      
                lastIndex = i;     
                // Update where maximum subset ends
            }
        }
        
        vector<int> temp;  
        // This will store our final answer
        
        temp.push_back(nums[lastIndex]);  
        // Insert the last element of the maximum subset
        
        // Reconstruct the subset using hash array
        while(hash[lastIndex] != lastIndex) {
            
            lastIndex = hash[lastIndex];  
            // Move to previous element in chain
            
            temp.push_back(nums[lastIndex]);  
            // Add that element into result
        }
        
        reverse(temp.begin(), temp.end());  
        // Reverse because we built subset from last to first
        
        return temp;  
        // Return the largest divisible subset
    }
};