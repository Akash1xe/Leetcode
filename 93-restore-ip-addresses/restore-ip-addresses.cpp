class Solution {
public:
    vector<string> ans;

    void solve(int idx, string &s, int parts, string curr) {

        // If we created 4 parts
        if (parts == 4) {
            // Valid only if entire string is used
            if (idx == s.size()) {
                curr.pop_back(); // remove last '.'
                ans.push_back(curr);
            }
            return;
        }

        // Try segment lengths 1, 2, 3
        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {

            string part = s.substr(idx, len);

            // Leading zero not allowed: "01", "00"
            if (part.size() > 1 && part[0] == '0')
                break;

            int num = stoi(part);

            // IP segment must be <= 255
            if (num > 255)
                break;

            solve(idx + len, s, parts + 1, curr + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {

        // IPv4 needs minimum 4 and maximum 12 digits
        if (s.size() < 4 || s.size() > 12)
            return {};

        solve(0, s, 0, "");

        return ans;
    }
};