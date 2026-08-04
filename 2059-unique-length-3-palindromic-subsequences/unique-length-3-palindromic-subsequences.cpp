class Solution {
public:
    int countPalindromicSubsequence(string s) {

        // Store first and last occurrence of each character
        vector<int> first(26, -1), last(26, -1);

        // Find first and last positions
        for (int i = 0; i < s.size(); i++) {

            int ch = s[i] - 'a';

            if (first[ch] == -1)
                first[ch] = i;

            last[ch] = i;
        }

        int ans = 0;

        // Try every character as the first and last character
        for (int ch = 0; ch < 26; ch++) {

            // Need at least one character between first and last
            if (first[ch] == -1 || last[ch] - first[ch] < 2)
                continue;

            unordered_set<char> middle;

            // Collect all distinct middle characters
            for (int i = first[ch] + 1; i < last[ch]; i++)
                middle.insert(s[i]);

            ans += middle.size();
        }

        return ans;
    }
};