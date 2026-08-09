class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        stack<int> st;
        int j = 0;

        for (int x : pushed) {

            // Push current element
            st.push(x);

            // Pop whenever the top matches
            // the next required popped element
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }

        return j == popped.size();
    }
};