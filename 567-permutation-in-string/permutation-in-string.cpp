
//Approach-3 (Sliding Window) - ACCEPTED
//T.C : O(m+n)
//S.C : O(26)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        // If s1 is larger than s2, no permutation can exist
        if (n > m) return false;

        // Frequency vectors for s1 and the current window in s2
        vector<int> s1_freq(26, 0);
        vector<int> s2_freq(26, 0);

        // Fill frequency of characters in s1
        for (int i = 0; i < n; i++) {
            s1_freq[s1[i] - 'a']++;
        }

        // Slide the window over s2
        int i = 0; // left index of the sliding window
        int j = 0; // right index of the sliding window
        while (j < m) {
            // Include a new character from the right end of the window
            s2_freq[s2[j] - 'a']++;

            // Check if the current window size matches the size of s1
            if (j - i + 1 > n) {
                // If we have passed the size of s1, we need to remove the leftmost character
                s2_freq[s2[i] - 'a']--;
                i++;
            }

            // Check if the current window's frequency matches s1's frequency
            if (s1_freq == s2_freq) {
                return true;
            }

            j++;
        }

        // No matching window found
        return false;
    }
};