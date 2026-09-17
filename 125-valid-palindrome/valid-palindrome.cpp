class Solution {
public:
    bool solve(string &s, int left, int right) {
        // Base case
        if (left >= right)
            return true;

        // Skip non-alphanumeric from left
        if (!isalnum(s[left]))
            return solve(s, left + 1, right);

        // Skip non-alphanumeric from right
        if (!isalnum(s[right]))
            return solve(s, left, right - 1);

        // Compare after converting to lowercase
        if (tolower(s[left]) != tolower(s[right]))
            return false;

        return solve(s, left + 1, right - 1);
    }

    bool isPalindrome(string s) {
        return solve(s, 0, s.size() - 1);
    }
};