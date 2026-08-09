class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<int> st;

        // Score of the outermost level
        st.push(0);

        for (char c : s) {

            if (c == '(') {

                // Start a new nested level
                st.push(0);

            } else {

                // Get the score inside the current pair
                int inside = st.top();
                st.pop();

                // "()" = 1
                // "(A)" = 2 * A
                int score = (inside == 0)
                                ? 1
                                : 2 * inside;

                // Add the current score to the previous level
                st.top() += score;
            }
        }

        return st.top();
    }
};

/*
Intuition:
- Use a stack to maintain the score of each nesting level.
- '(' creates a new level, so push 0.
- ')' closes the current level.
- If the inside score is 0, we have "()", which scores 1.
- Otherwise, we have "(A)", which scores 2 * A.
- Add the calculated score to the previous level.

Time Complexity: O(n)
Space Complexity: O(n)
*/