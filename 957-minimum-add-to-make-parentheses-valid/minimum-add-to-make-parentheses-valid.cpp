class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;

        for (char c : s) {

            if (c == '(') {
                // We have one more unmatched opening bracket.
                open++;
            }
            else {
                // If there is an opening bracket, match it.
                if (open > 0) {
                    open--;
                }
                else {
                    // No '(' is available, so we must add one '('.
                    ans++;
                }
            }
        }

        // Any remaining '(' need a ')' each.
        return ans + open;
    }
};