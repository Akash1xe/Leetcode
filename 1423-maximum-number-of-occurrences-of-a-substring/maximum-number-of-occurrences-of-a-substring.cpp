class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        // Frequency of characters inside the current sliding window
        unordered_map<char, int> freq;

        // Stores how many times each valid substring appears
        unordered_map<string, int> count;
        
        // Left pointer of the sliding window
        int i = 0;

        // Number of distinct characters in the current window
        int distinct = 0;

        // Maximum frequency of any valid substring
        int ans = 0;
        
        // Expand the window using j
        for (int j = 0; j < s.size(); j++) {
            
            // Add current character to the window
            freq[s[j]]++;
            
            // If frequency becomes 1,
            // this character has appeared for the first time in the window
            if (freq[s[j]] == 1)
                distinct++;
            
            
            // We only need to check substrings of length minSize.
            // If window becomes larger than minSize,
            // remove the leftmost character.
            if (j - i + 1 > minSize) {
                
                freq[s[i]]--;
                
                // If frequency becomes 0,
                // this character no longer exists in the window
                if (freq[s[i]] == 0) {
                    distinct--;
                    freq.erase(s[i]);
                }
                
                // Move the left pointer forward
                i++;
            }
            
            
            // Process the window only when its size is exactly minSize
            if (j - i + 1 == minSize) {
                
                // A substring is valid only if it contains
                // at most maxLetters distinct characters
                if (distinct <= maxLetters) {
                    
                    // Extract the current valid substring
                    string sub = s.substr(i, minSize);
                    
                    // Increase its occurrence count
                    count[sub]++;
                    
                    // Update the maximum occurrence found so far
                    ans = max(ans, count[sub]);
                }
            }
        }
        
        // Return the maximum number of occurrences
        return ans;
    }
};