class Solution {
public:

    double power(double x, long long n) {

        // x^0 = 1
        if (n == 0) {
            return 1.0;
        }

        // x^1 = x
        if (n == 1) {
            return x;
        }

        // Even power:
        // x^n = (x*x)^(n/2)
        if (n % 2 == 0) {
            return power(x * x, n / 2);
        }

        // Odd power:
        // x^n = x * x^(n-1)
        return x * power(x, n - 1);
    }

    double myPow(double x, int n) {

        // Convert to long long to safely handle INT_MIN
        long long powerN = n;

        // Negative exponent
        if (powerN < 0) {
            return 1.0 / power(x, -powerN);
        }

        return power(x, powerN);
    }
};