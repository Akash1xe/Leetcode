class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        // Stores the maximum frequency required for each character
        vector<int> need(26, 0);

        // Build the global requirement from words2
        for (string word : words2) {

            vector<int> freq(26, 0);

            for (char ch : word)
                freq[ch - 'a']++;

            for (int i = 0; i < 26; i++)
                need[i] = max(need[i], freq[i]);
        }

        vector<string> ans;

        // Check every word in words1
        for (string word : words1) {

            vector<int> freq(26, 0);

            for (char ch : word)
                freq[ch - 'a']++;

            bool ok = true;

            // Verify whether current word satisfies all requirements
            for (int i = 0; i < 26; i++) {
                if (freq[i] < need[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans.push_back(word);
        }

        return ans;
    }
};

/*
Time Complexity: O((N + M) * L)
Space Complexity: O(1)
*/