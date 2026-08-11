class Solution {
public:
    string removeDuplicateLetters(string s) {

        // Count how many times each character appears
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Track whether character is already in stack
        vector<bool> used(26, false);

        stack<char> st;

        for (char c : s) {

            // Current character is now being processed
            freq[c - 'a']--;

            // If already present, don't add it again
            if (used[c - 'a']) {
                continue;
            }

            // Remove larger characters if:
            // 1. They are bigger than current character
            // 2. They will appear again later
            while (!st.empty() &&
                   st.top() > c &&
                   freq[st.top() - 'a'] > 0) {

                used[st.top() - 'a'] = false;
                st.pop();
            }

            // Add current character
            st.push(c);
            used[c - 'a'] = true;
        }

        // Build answer from stack
        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};