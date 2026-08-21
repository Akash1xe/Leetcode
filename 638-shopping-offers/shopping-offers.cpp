class Solution {
public:
    map<vector<int>, int> dp;

    int solve(vector<int>& price, vector<vector<int>>& special,
              vector<int>& needs) {

        // Already calculated this state
        if (dp.count(needs)) {
            return dp[needs];
        }

        // Option 1: Buy everything normally
        int ans = 0;

        for (int i = 0; i < needs.size(); i++) {
            ans += needs[i] * price[i];
        }

        // Option 2: Try every special offer
        for (auto& offer : special) {

            bool canUse = true;

            // Copy current needs
            vector<int> newNeeds = needs;

            // Check if this offer can be used
            for (int i = 0; i < needs.size(); i++) {

                // Offer requires more items than we need
                if (offer[i] > needs[i]) {
                    canUse = false;
                    break;
                }

                // Reduce the needs
                newNeeds[i] -= offer[i];
            }

            // If offer is valid, try it
            if (canUse) {

                // offer.back() = price of the special offer
                ans = min(ans, offer.back() + solve(price, special, newNeeds));
            }
        }

        // Store answer for this needs state
        return dp[needs] = ans;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
                       vector<int>& needs) {

        return solve(price, special, needs);
    }
};