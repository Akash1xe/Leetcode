class Solution {
public:

    // Helper function to reverse characters from index left to right
    void reverseRange(string &s, int left, int right) {

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    string reverseWords(string s) {

        // Step 1:
        // Reverse complete string
        // Example:
        // "the sky is blue"
        // becomes
        // "eulb si yks eht"
        reverse(s.begin(), s.end());

        int n = s.length();

        int left = 0;
        int right = 0;
        int i = 0;

        while (i < n) {

            // Step 2:
            // Skip spaces
            while (i < n && s[i] == ' ') {
                i++;
            }

            // If we reached the end
            if (i == n) {
                break;
            }

            // Step 3:
            // Copy current word toward the front
            //
            // Example:
            // eulb
            // gets copied first
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }

            // Step 4:
            // Reverse this individual word
            //
            // "eulb" -> "blue"
            reverseRange(s, left, right - 1);

            // Add one space after the word
            s[right++] = ' ';

            // Next word will start here
            left = right;
        }

        // Remove the extra space added after the last word
        if (right > 0) {
            s.resize(right - 1);
        }

        return s;
    }
};