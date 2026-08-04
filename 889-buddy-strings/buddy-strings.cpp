class Solution {
public:
    bool buddyStrings(string s, string goal) {

        // Lengths must be equal
        if (s.size() != goal.size())
            return false;

        // If both strings are already equal
        if (s == goal) {

            vector<int> freq(26, 0);

            // Check whether any character appears twice
            for (char ch : s) {

                freq[ch - 'a']++;

                if (freq[ch - 'a'] > 1)
                    return true;
            }

            return false;
        }

        vector<int> diff;

        // Store mismatch positions
        for (int i = 0; i < s.size(); i++) {

            if (s[i] != goal[i])
                diff.push_back(i);
        }

        // Exactly two mismatches are required
        if (diff.size() != 2)
            return false;

        return s[diff[0]] == goal[diff[1]] &&
               s[diff[1]] == goal[diff[0]];
    }
};

/*
Time Complexity : O(n)
Space Complexity : O(1)
*/