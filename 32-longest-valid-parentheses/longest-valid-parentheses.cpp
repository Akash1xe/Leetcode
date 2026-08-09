class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;

        // Boundary before the string starts
        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            // Opening bracket
            if (s[i] == '(') {
                st.push(i);
            }

            // Closing bracket
            else {

                st.pop();

                // No matching opening bracket
                if (st.empty()) {
                    st.push(i);
                }

                // Valid substring found
                else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};

/*
Intuition:

We use a stack of indices.

The stack stores the indices of unmatched '('
and also acts as a boundary for the current valid substring.

Initially, we push -1 because it represents the position
before the string starts.

When we see '(':
    push its index.

When we see ')':
    pop the previous index because we try to match
    this ')' with an opening '('.

If the stack becomes empty:
    there is no valid opening '(' available.
    Therefore, the current ')' becomes the new boundary.

Otherwise:
    the substring from st.top() + 1 to i is valid.

    Its length is:
        i - st.top()

Take the maximum length found.

Time Complexity: O(n)
Space Complexity: O(n)
*/