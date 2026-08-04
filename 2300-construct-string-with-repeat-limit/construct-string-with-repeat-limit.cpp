class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {

        // Store the frequency of each character
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string ans;

        // Start from the largest character ('z')
        int i = 25;

        while (i >= 0) {

            // If this character is not available, move to the next smaller one
            if (freq[i] == 0) {
                i--;
                continue;
            }

            // Use this character as many times as possible
            // but not more than repeatLimit
            int use = min(freq[i], repeatLimit);

            while (use--) {
                ans.push_back(char(i + 'a'));
            }

            // Reduce its frequency
            freq[i] -= min(freq[i], repeatLimit);

            // If all copies are used, move to the next smaller character
            if (freq[i] == 0) {
                i--;
                continue;
            }

            // We still have this character left.
            // We need one smaller character to break the consecutive sequence.
            int j = i - 1;

            // Find the next available smaller character
            while (j >= 0 && freq[j] == 0) {
                j--;
            }

            // No smaller character exists.
            // We cannot place the remaining larger characters.
            if (j < 0)
                break;

            // Insert exactly one smaller character
            ans.push_back(char(j + 'a'));

            // Decrease its frequency
            freq[j]--;
        }

        return ans;
    }
};

/*
Time Complexity : O(n)
- Counting frequencies: O(n)
- Building answer: O(n)
- Searching for next smaller character is over only 26 letters,
  so it is effectively constant time.

Space Complexity : O(1)
- Only a frequency array of size 26 is used.
*/