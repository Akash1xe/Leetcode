class Solution {
public:
    void remove(int index, int open, int close, int leftRemove, int rightRemove,
                string& curr, string& s, unordered_set<string>& st) {

        // Reached end
        if (index == s.size()) {

            // Used exactly the required removals
            // and parentheses are balanced
            if (leftRemove == 0 && rightRemove == 0 && open == close) {

                st.insert(curr);
            }

            return;
        }

        char ch = s[index];

        // ----------------------------
        // CASE 1: '('
        // ----------------------------
        if (ch == '(') {

            // Option 1: REMOVE '('
            if (leftRemove > 0) {
                remove(index + 1, open, close, leftRemove - 1, rightRemove,
                       curr, s, st);
            }

            // Option 2: KEEP '('
            curr.push_back('(');

            remove(index + 1, open + 1, close, leftRemove, rightRemove, curr, s,
                   st);

            curr.pop_back();
        }

        // ----------------------------
        // CASE 2: ')'
        // ----------------------------
        else if (ch == ')') {

            // Option 1: REMOVE ')'
            if (rightRemove > 0) {

                remove(index + 1, open, close, leftRemove, rightRemove - 1,
                       curr, s, st);
            }

            // Option 2: KEEP ')'
            // Only when an unmatched '(' exists
            if (open > close) {

                curr.push_back(')');

                remove(index + 1, open, close + 1, leftRemove, rightRemove,
                       curr, s, st);

                curr.pop_back();
            }
        }

        // ----------------------------
        // CASE 3: normal character
        // ----------------------------
        else {

            curr.push_back(ch);

            remove(index + 1, open, close, leftRemove, rightRemove, curr, s,
                   st);

            curr.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Step 1: calculate minimum removals
        for (char ch : s) {

            if (ch == '(') {
                leftRemove++;
            }

            else if (ch == ')') {

                if (leftRemove > 0)
                    leftRemove--;

                else
                    rightRemove++;
            }
        }

        unordered_set<string> st;
        string curr = "";

        remove(0, 0, 0, leftRemove, rightRemove, curr, s, st);

        return vector<string>(st.begin(), st.end());
    }
};