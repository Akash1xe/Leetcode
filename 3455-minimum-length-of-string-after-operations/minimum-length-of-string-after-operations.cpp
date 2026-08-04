class Solution {
public:
    int minimumLength(string s) {

        // Frequency of each lowercase letter
        vector<int> freq(26, 0);

        // Count occurrences
        for (char ch : s)
            freq[ch - 'a']++;

        int ans = 0;

        // Process every character
        for (int count : freq) {

            // Ignore characters not present
            if (count == 0)
                continue;

            // Odd frequency -> 1 character remains
            if (count % 2 == 1)
                ans += 1;

            // Even frequency -> 2 characters remain
            else
                ans += 2;
        }

        return ans;
    }
};

/*
Time Complexity : O(n)
Space Complexity: O(1)
*/