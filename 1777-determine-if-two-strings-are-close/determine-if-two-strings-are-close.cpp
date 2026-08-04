class Solution {
public:
    bool closeStrings(string word1, string word2) {

        // If lengths are different, transformation is impossible
        if (word1.size() != word2.size())
            return false;

        // Frequency arrays for 26 lowercase letters
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Count frequency of each character
        for (char ch : word1)
            freq1[ch - 'a']++;

        for (char ch : word2)
            freq2[ch - 'a']++;

        // Check that both strings contain exactly the same characters
        for (int i = 0; i < 26; i++) {

            // Character exists in only one string
            if ((freq1[i] == 0) != (freq2[i] == 0))
                return false;
        }

        // Sort frequencies
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        // Frequencies must match
        return freq1 == freq2;
    }
};