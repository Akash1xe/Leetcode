class Solution {
public:
    int fib(int n) {
        // Base case
        if (n == 0 || n == 1)
            return n;

        // Recursive case
        return fib(n - 1) + fib(n - 2);
    }
};