class Solution {
public:

    bool checkValidString(string s) {

        // minOpen = minimum possible number of '(' currently open
        // maxOpen = maximum possible number of '(' currently open
        //
        // We keep a range [minOpen, maxOpen] because '*' can have
        // different meanings: '(' , ')' or empty.
        int minOpen = 0;
        int maxOpen = 0;

        // Process every character from left to right
        for (char c : s) {

            // If current character is '('
            if (c == '(') {

                // '(' definitely increases the number of open brackets
                minOpen++;
                maxOpen++;
            }

            // If current character is ')'
            else if (c == ')') {

                // ')' definitely closes one open bracket
                minOpen--;
                maxOpen--;
            }

            // If current character is '*'
            else {

                // '*' can be ')'
                // Therefore minimum number of open brackets decreases
                minOpen--;

                // '*' can be '('
                // Therefore maximum number of open brackets increases
                maxOpen++;

                // '*' can also be empty
                // We don't need to explicitly handle empty here
                // because the range already covers that possibility.
            }

            // If even the maximum possible number of open brackets
            // becomes negative, there is no way to make the string valid.
            //
            // Example:
            // s = ")"
            // maxOpen = -1
            //
            // There is no '(' or '*' available to match ')'.
            if (maxOpen < 0) {
                return false;
            }

            // minOpen can never actually be negative.
            //
            // If minOpen becomes negative, it means we have enough '*'
            // to choose them as empty or '(' instead of ')'.
            //
            // So the minimum possible number of open brackets is 0.
            minOpen = max(minOpen, 0);
        }

        // At the end, if minOpen == 0,
        // there exists some way to assign '*' such that
        // every '(' is matched with a ')'.
        return minOpen == 0;
    }
};

/*
INTUITION:

The difficult part of this problem is '*'.

A '*' can represent:

    '('
    ')'
    ''

So instead of deciding immediately what every '*' means,
we keep a RANGE of possible open brackets.

        minOpen ---------------- maxOpen
           ↓                         ↓
     minimum opens             maximum opens


For '(':

    minOpen++
    maxOpen++

Because '(' must be an opening bracket.


For ')':

    minOpen--
    maxOpen--

Because ')' must close an opening bracket.


For '*':

    minOpen--
    maxOpen++

Why?

For the MINIMUM:
    We can treat '*' as ')'.

For the MAXIMUM:
    We can treat '*' as '('.

The empty option is automatically covered by the range.


IMPORTANT CHECK:

if (maxOpen < 0)

This means even in the BEST case we have more ')' than
we can possibly match.

Therefore the answer is immediately false.


At the end:

    return minOpen == 0;

Why?

If minOpen == 0, it means there is at least one possible
way to choose the '*' characters so that all '(' are closed.

So:

    maxOpen < 0  → impossible → false

    minOpen == 0 → possible → true


TIME COMPLEXITY:
    O(n)

We visit every character exactly once.


SPACE COMPLEXITY:
    O(1)

We only use two integer variables.
*/