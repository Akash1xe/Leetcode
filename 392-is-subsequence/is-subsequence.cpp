class Solution {
public:
    bool isSubsequence(string s, string t) {

        int i = 0; // Pointer for s
        int j = 0; // Pointer for t

        // Traverse both strings
        while (i < s.size() && j < t.size()) {

            // Current characters match
            if (s[i] == t[j])
                i++;

            // Always move pointer of t
            j++;
        }

        // All characters of s were matched
        return i == s.size();
    }
};

/*
Time Complexity : O(n)
Space Complexity : O(1)
*/