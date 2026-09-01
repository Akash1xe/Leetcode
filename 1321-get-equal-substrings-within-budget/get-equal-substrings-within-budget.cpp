class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {

        int left = 0;
        int cost = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // Include right's conversion cost
            cost += abs(s[right] - t[right]);

            // Invalid window: budget exceeded
            while (cost > maxCost) {

                // Remove left's cost
                cost -= abs(s[left] - t[left]);

                left++;
            }

            // Valid window
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};