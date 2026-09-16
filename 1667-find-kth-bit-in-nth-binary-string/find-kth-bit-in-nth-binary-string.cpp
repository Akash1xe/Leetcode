class Solution {
public:

    string solve(int n) {

        // Base case
        if (n == 1) {
            return "0";
        }

        // Generate S(n-1)
        string prev = solve(n - 1);

        // Copy it because we need original prev also
        string temp = prev;

        // Invert
        for (char &ch : temp) {
            ch = (ch == '0') ? '1' : '0';
        }

        // Reverse
        reverse(temp.begin(), temp.end());

        // Sn = S(n-1) + "1" + reverse(invert(S(n-1)))
        return prev + "1" + temp;
    }

    char findKthBit(int n, int k) {

        string s = solve(n);

        // k is 1-indexed, string is 0-indexed
        return s[k - 1];
    }
};