class Solution {
public:
    int kthGrammar(int n, int k) {
        // Base case: first row is always "0"
        if (n == 1) {
            return 0;
        }

        // Find the parent position in previous row
        int parent = kthGrammar(n - 1, (k + 1) / 2);

        // Odd position -> same as parent
        if (k % 2 == 1) {
            return parent;
        }

        // Even position -> opposite of parent
        return 1 - parent;
    }
};