class Solution {
public:
    int maximumLengthSubstring(string s) {

        int ans = 0;
        int n = s.length();

        vector<int> freq(26, 0);

        int left = 0;

        for (int right = 0; right < n; right++) {

            // Add the current character to the window
            freq[s[right] - 'a']++;

            // If current character appears more than 2 times,
            // shrink the window from the left.
            while (freq[s[right] - 'a'] > 2) {

                // Remove the character at left
                freq[s[left] - 'a']--;

                // Move left forward
                left++;
            }

            // Current window [left ... right] is valid
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};