class Solution {
public:
    string customSortString(string order, string s) {

        // Frequency array to count occurrences of each character in s
        vector<int> freq(26, 0);

        // Count frequency of every character in s
        for (char ch : s)
            freq[ch - 'a']++;

        string ans = "";

        // Add characters according to the custom order
        for (char ch : order) {

            // Append this character as many times as it appears
            while (freq[ch - 'a'] > 0) {
                ans += ch;
                freq[ch - 'a']--;
            }
        }

        // Add remaining characters that were not present in order
        for (int i = 0; i < 26; i++) {

            while (freq[i] > 0) {
                ans += char(i + 'a');
                freq[i]--;
            }
        }

        return ans;
    }
};

/*
Time Complexity: O(n + m + 26)
n = length of s
m = length of order

Space Complexity: O(26) = O(1)
*/