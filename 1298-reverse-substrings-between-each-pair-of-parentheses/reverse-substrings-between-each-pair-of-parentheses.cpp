class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string current = "";

        for (char c : s) {

            // Start a new nested level
            if (c == '(') {
                st.push(current);
                current = "";
            }

            // Finish the current level
            else if (c == ')') {
                reverse(current.begin(), current.end());

                current = st.top() + current;
                st.pop();
            }

            // Normal character
            else {
                current += c;
            }
        }

        return current;
    }
};