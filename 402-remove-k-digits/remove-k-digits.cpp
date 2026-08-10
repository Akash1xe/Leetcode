class Solution {
public:
    string removeKdigits(string num, int k) {

        // Stack will store the digits of the smallest number
        string st;

        int n = num.length();

        // If we have to remove all digits
        // the smallest number is "0"
        if (k == n)
            return "0";


        // Traverse every digit
        for (int i = 0; i < n; i++) {

            char value = num[i];

            // If the current digit is smaller than the
            // digit at the top of the stack,
            // removing the bigger digit will make
            // the number smaller.
            //
            // Keep doing this while:
            // 1. Stack is not empty
            // 2. Top digit > current digit
            // 3. We still have digits to remove
            while (!st.empty() &&
                   st.back() > value &&
                   k > 0) {

                // Remove the bigger digit
                st.pop_back();

                // One deletion is used
                k--;
            }

            // Add current digit
            st.push_back(value);
        }


        // If we still have digits left to remove,
        // remove them from the end.
        //
        // This happens when the digits are already
        // in increasing/equal order.
        while (k > 0) {

            st.pop_back();
            k--;
        }


        // Remove leading zeroes
        int start = 0;

        while (start < st.length() && st[start] == '0') {
            start++;
        }


        // If everything was zero
        // return "0"
        if (start == st.length())
            return "0";


        // Return number without leading zeroes
        return st.substr(start);


        /*
        ============================================================
                            INTUITION
        ============================================================

        We want to make the number as SMALL as possible.

        Consider:

                1432219
                  ↑
                4 > 3

        If we have the choice to remove one digit,
        removing 4 is better than removing 3:

                143...
                 ↓
                13...

        Therefore:

        If current digit < previous digit,
        remove the previous bigger digit.

        This is exactly what the monotonic stack does.

        ------------------------------------------------------------

        Example:

                num = "1432219"
                k = 3

        Start:

                stack = ""

        Read 1:

                stack = "1"

        Read 4:

                stack = "14"

        Read 3:

                4 > 3
                Remove 4

                stack = "1"
                k = 2

                Push 3

                stack = "13"

        Read 2:

                3 > 2
                Remove 3

                stack = "1"
                k = 1

                Push 2

                stack = "12"

        Read 2:

                2 is not greater than 2

                stack = "122"

        Read 1:

                2 > 1
                Remove 2

                stack = "12"
                k = 0

                Push 1

                stack = "121"

        Read 9:

                k = 0
                so simply push

                stack = "1219"


        Final answer:

                "1219"


        ------------------------------------------------------------

        Why do we remove from the END if k is still left?

        Example:

                num = "12345"
                k = 2

        There is no bigger digit before a smaller digit.

                1 < 2 < 3 < 4 < 5

        So the number is already increasing.

        The best choice is to remove the largest digits
        from the end:

                12345
                   ↓
                123

        Therefore:

                while(k > 0)
                    pop_back();


        ------------------------------------------------------------

        IMPORTANT PATTERN:

        This is a MONOTONIC STACK problem.

        Whenever you see:

        "Remove K elements to make something smallest/largest"

        Think:

                Current element
                      ↓
                Compare with stack top
                      ↓
                If removing stack top improves answer
                      ↓
                POP
                      ↓
                Push current element

        Time Complexity:
                O(n)

        Each digit is pushed once and popped at most once.

        Space Complexity:
                O(n)

        ============================================================
        */
    }
};