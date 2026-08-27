class Solution {
public:
    const long long MOD = 1e9 + 7;

    // Fast exponentiation: calculates base^power % MOD
    long long power(long long base, long long power) {
        long long ans = 1;

        while (power > 0) {

            // If power is odd
            if (power % 2 == 1) {
                ans = (ans * base) % MOD;
            }

            base = (base * base) % MOD;
            power /= 2;
        }

        return ans;
    }

    int countGoodArrays(int n, int m, int k) {

        // factorial[i] = i!
        vector<long long> factorial(n);

        factorial[0] = 1;

        for (int i = 1; i < n; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }


        /*
            We need:

                C(n - 1, k)

            Formula:

                     (n - 1)!
            C = -------------------
                 k! * (n - 1 - k)!
        */

        long long numerator = factorial[n - 1];

        long long denominator =
            (factorial[k] * factorial[n - 1 - k]) % MOD;


        // Modular inverse using Fermat's Little Theorem:
        //
        // 1 / x  ≡  x^(MOD - 2) mod MOD
        long long combination =
            (numerator * power(denominator, MOD - 2)) % MOD;


        /*
            First element:
                m choices
        */

        long long firstElementChoices = m;


        /*
            Total adjacent comparisons = n - 1

            Exactly k comparisons are equal.

            So different comparisons:

                n - 1 - k

            Every different comparison has:

                m - 1 choices
        */

        long long differentChoices =
            power(m - 1, n - 1 - k);


        // Final formula:
        //
        // C(n-1, k) * m * (m-1)^(n-1-k)

        long long answer = combination;

        answer = (answer * firstElementChoices) % MOD;
        answer = (answer * differentChoices) % MOD;

        return answer;
    }
};