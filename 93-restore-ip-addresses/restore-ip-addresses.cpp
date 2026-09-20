class Solution {
public:
    vector<string> ans;

    void solve(int idx, string &s, int parts, string curr) {

        // Exactly 4 parts used
        if (parts == 4) {
            if (idx == s.size()) {
                // Remove last '.'
                curr.pop_back();
                ans.push_back(curr);
            }
            return;
        }

        // Try length 1, 2, 3
        for (int len = 1; len <= 3; len++) {

            if (idx + len > s.size())
                break;

            string part = s.substr(idx, len);

            // Leading zero not allowed: "01", "00"
            if (part.size() > 1 && part[0] == '0')
                break;

            int num = stoi(part);

            // IP number cannot exceed 255
            if (num > 255)
                break;

            solve(idx + len,
                  s,
                  parts + 1,
                  curr + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {

        // Minimum 4 digits, maximum 12 digits
        if (s.size() < 4 || s.size() > 12)
            return {};

        solve(0, s, 0, "");

        return ans;
    }
};