class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<bool> used(26, false);

        stack<char> st;

        for (char c : s) {

            // Current character is no longer "remaining"
            freq[c - 'a']--;

            // Already present in answer
            if (used[c - 'a']) {
                continue;
            }

            // Remove larger characters if they appear again later
            while (!st.empty() &&
                   st.top() > c &&
                   freq[st.top() - 'a'] > 0) {

                used[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            used[c - 'a'] = true;
        }

        string ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};