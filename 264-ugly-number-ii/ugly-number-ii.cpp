class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> ugly(n + 1);

        int i2 = 1;
        int i3 = 1;
        int i5 = 1;

        ugly[1] = 1;

        for (int i = 2; i <= n; i++) {
            int i_2ugly = ugly[i2] * 2;
            int i_3ugly = ugly[i3] * 3;
            int i_5ugly = ugly[i5] * 5;

            int miniUgly = min({i_2ugly, i_3ugly, i_5ugly});

            ugly[i] = miniUgly;

            if (i_2ugly == miniUgly) {
                i2++;
            }

            if (i_3ugly == miniUgly) {
                i3++;
            }

            if (i_5ugly == miniUgly) {
                i5++;
            }
        }

        return ugly[n]; 
    }
};