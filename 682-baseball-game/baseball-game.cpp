class Solution {
public:
    int calPoints(vector<string>& operations) {

        // Stack stores all valid scores.
        // The top of the stack is the most recent score.
        stack<int> st;

        // Process each operation one by one.
        for (string op : operations) {

            // If the operation is "C",
            // cancel/remove the previous score.
            if (op == "C") {

                st.pop();
            }

            // If the operation is "D",
            // add double of the previous score.
            else if (op == "D") {

                int previous = st.top();

                st.push(previous * 2);
            }

            // If the operation is "+",
            // add the sum of the previous two scores.
            else if (op == "+") {

                int last = st.top();

                // Remove the last score temporarily
                // so that we can access the second-last score.
                st.pop();

                int secondLast = st.top();

                // Put the last score back.
                st.push(last);

                // Add the sum of the previous two scores.
                st.push(last + secondLast);
            }

            // Otherwise, the operation is a number.
            else {

                // Convert string to integer and push it.
                st.push(stoi(op));
            }
        }

        // Add all valid scores in the stack.
        int ans = 0;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

/*
Intuition:

We use a stack because the problem always asks about
the most recent scores.

The stack stores only valid scores.

For a number:
    Push it into the stack.

For "C":
    Remove the most recent score using pop().

For "D":
    Look at the most recent score using top(),
    double it, and push the new score.

For "+":
    We need the previous two scores.
    The top is the most recent score.
    Temporarily remove it to access the second-last score.
    Add both scores and push their sum.

At the end, all remaining values in the stack are valid
scores, so we add them to get the final answer.

Time Complexity:
O(n)

We process every operation once, and the final traversal
also takes O(n).

Space Complexity:
O(n)

In the worst case, all operations can create valid scores
and remain in the stack.
*/