class Solution {
public:
    int countGoodSubstrings(string s) {
        
        // Frequency map to store the frequency
        // of characters inside the current window
        unordered_map<char, int> freq;

        // Left pointer of the sliding window
        int i = 0;

        // Number of good substrings found
        int cnt = 0;

        // Right pointer of the sliding window
        int r = 0;

        // Length of the string
        int n = s.length();

        // We need a fixed window of size 3
        while (r < n) {

            // Add the current character to the window
            freq[s[r]]++;

            // When window size becomes exactly 3
            if (r - i + 1 == 3) {

                // If map size is 3, all 3 characters
                // are distinct, so this is a good substring
                if (freq.size() == 3) {
                    cnt++;
                }

                // Before moving the window forward,
                // remove the leftmost character
                freq[s[i]]--;

                // If its frequency becomes 0,
                // completely remove it from the map
                if (freq[s[i]] == 0) {
                    freq.erase(s[i]);
                }

                // Move left pointer forward
                i++;
            }

            // Expand window from the right
            r++;
        }

        // Return total number of substrings of length 3
        // containing 3 distinct characters
        return cnt;
    }
};