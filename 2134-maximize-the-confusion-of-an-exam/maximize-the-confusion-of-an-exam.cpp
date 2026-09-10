class Solution {
public:
    int solve(string& s, int k, char bad) {
        int left = 0;
        int badCount = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // Count characters that need to be changed
            if (s[right] == bad) {
                badCount++;
            }

            // More than k changes required -> shrink window
            while (badCount > k) {

                if (s[left] == bad) {
                    badCount--;
                }

                left++;
            }

            // Window requires at most k changes
            ans = max(ans, right - left + 1);
        }

        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {

        // Make all characters T -> F is bad
        int makeAllT = solve(answerKey, k, 'F');

        // Make all characters F -> T is bad
        int makeAllF = solve(answerKey, k, 'T');

        return max(makeAllT, makeAllF);
    }
};