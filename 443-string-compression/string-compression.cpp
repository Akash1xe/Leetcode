class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();

        // left points to the start of the current group
        int left = 0;

        // write tells us where to store the compressed result
        int write = 0;

        // Process every group of consecutive characters
        while (left < n) {

            // right will move until the current character changes
            int right = left;

            // Move right while characters are same as chars[left]
            while (right < n && chars[right] == chars[left]) {
                right++;
            }

            // Number of consecutive occurrences of current character
            int count = right - left;

            // Store the current character in the compressed array
            chars[write] = chars[left];
            write++;

            // If character occurs more than once,
            // store its frequency after the character
            if (count > 1) {

                // Convert count into string because count can be 12, 15, 100, etc.
                string freq = to_string(count);

                // Store every digit separately
                // Example: count = 12 -> store '1' then '2'
                for (char digit : freq) {
                    chars[write] = digit;
                    write++;
                }
            }

            // Move left to the beginning of the next group
            left = right;
        }

        // write is the final length of the compressed array
        return write;
    }
};