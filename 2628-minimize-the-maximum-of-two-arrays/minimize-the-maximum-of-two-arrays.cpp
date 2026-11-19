class Solution {
public:
    bool isValid(long long mid, int divisor1, int divisor2, int uniqueCnt1,
                 int uniqueCnt2) {

        long long lcm = (1LL * divisor1 / gcd(divisor1, divisor2)) * divisor2;

        long long count1 = mid - mid / divisor1;
        long long count2 = mid - mid / divisor2;

        long long totalCount = mid - mid / lcm;

        return count1 >= uniqueCnt1 && count2 >= uniqueCnt2 &&
               totalCount >= (long long)uniqueCnt1 + uniqueCnt2;
    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1,
                    int uniqueCnt2) {

        long long low = 1;
        long long high = 1e10;

        long long ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isValid(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2)) {

                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};