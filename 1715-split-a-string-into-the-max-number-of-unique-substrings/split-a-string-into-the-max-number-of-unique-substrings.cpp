class Solution {
public:

    int solve(int ind, string& s, unordered_set<string>& used) {

        // If we have used the whole string
        if (ind == s.size()) {
            return 0;
        }

        int ans = 0;

        string curr = "";

        // Try every possible substring starting from ind
        for (int i = ind; i < s.size(); i++) {

            curr += s[i];

            // Only take it if this substring is unique
            if (used.find(curr) == used.end()) {

                // Pick
                used.insert(curr);

                // Recurse for remaining string
                ans = max(ans, 1 + solve(i + 1, s, used));

                // Backtrack
                used.erase(curr);
            }
        }

        return ans;
    }

    int maxUniqueSplit(string s) {

        unordered_set<string> used;

        return solve(0, s, used);
    }
};