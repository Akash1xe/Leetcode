class Solution {
public:
    int calculate(string s) {

        int n = s.length();          // length of the input expression
        long long result = 0;              // stores the current calculated result
        long long number = 0;              // stores the current number being formed from digits
        int sign = 1;                // current sign (+1 for + , -1 for -)

        stack<long long> st;               // stack used to store previous result and sign when '(' appears

        for (int i = 0; i < n; i++) {   // traverse the whole string

            if (isdigit(s[i])) {        // if current character is a digit

                // build the number (handles multi-digit numbers like 123)
                 number = number * 10 + (s[i] - '0');  // build number

            } 
            else if (s[i] == '+') {     // if we encounter '+'

                result += number * sign; // add previous number to result with its sign
                number = 0;              // reset number for the next value
                sign = 1;                // update sign to positive

            } 
            else if (s[i] == '-') {     // if we encounter '-'

                result += number * sign; // add previous number to result
                number = 0;              // reset number
                sign = -1;               // update sign to negative

            } 
            else if (s[i] == '(') {     // if we encounter '(' start of a sub-expression

                st.push(result);        // store current result in stack
                st.push(sign);          // store current sign in stack

                result = 0;             // reset result for new expression inside parentheses
                sign = 1;               // reset sign

            } 
            else if (s[i] == ')') {     // if we encounter ')' end of sub-expression

                result += number * sign; // complete the calculation inside parentheses
                number = 0;              // reset number

                int stackSign = st.top(); // retrieve sign before '('
                st.pop();

                int lastResult = st.top(); // retrieve result before '('
                st.pop();

                result *= stackSign;       // apply the stored sign to current result
                result += lastResult;      // add previous result to combine expressions
            }
        }

        result += number * sign;  // add the last number after the loop finishes

        return result;            // return final evaluated result
    }
};