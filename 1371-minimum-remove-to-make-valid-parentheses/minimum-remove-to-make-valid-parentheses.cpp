class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;

        // First pass:
        // Find invalid ')' and unmatched '('
        for (int i = 0; i < s.size(); i++) {

            // If we see an opening bracket,
            // store its index because it may need a matching ')'
            if (s[i] == '(') {
                st.push(i);
            }

            // If we see a closing bracket
            else if (s[i] == ')') {

                // If there is an unmatched '(',
                // this ')' can match with it
                if (!st.empty()) {
                    st.pop();
                }

                // Otherwise this ')' is invalid
                else {
                    s[i] = '#';
                }
            }
        }

        // Any '(' left in the stack has no matching ')',
        // so mark those '(' as invalid
        while (!st.empty()) {
            s[st.top()] = '#';
            st.pop();
        }

        // Build the final valid string
        string ans;

        for (char c : s) {
            if (c != '#') {
                ans += c;
            }
        }

        return ans;
    }
};