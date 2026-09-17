class Solution {
public:
    char findKthBit(int n, int k) {

        // Base case
        if (n == 1)
            return '0';

        int len = (1 << n) - 1;
        int mid = len / 2 + 1;

        // Middle bit is always 1
        if (k == mid)
            return '1';

        // Left half is exactly S(n-1)
        if (k < mid)
            return findKthBit(n - 1, k);

        // Right half is reverse + invert of S(n-1)
        int mirror = len - k + 1;

        char bit = findKthBit(n - 1, mirror);

        // Invert the answer
        return bit == '0' ? '1' : '0';
    }
};