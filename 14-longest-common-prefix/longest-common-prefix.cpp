class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty()) return "";

        // Assume first string is our prefix
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {

            // Keep reducing prefix until strs[i]
            // starts with prefix
            while (strs[i].find(prefix) != 0) {

                // Remove last character
                prefix.pop_back();

                // No common prefix
                if (prefix.empty()) {
                    return "";
                }
            }
        }

        return prefix;
    }
};