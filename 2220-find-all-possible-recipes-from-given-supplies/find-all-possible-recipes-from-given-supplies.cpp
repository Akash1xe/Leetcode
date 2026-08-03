/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=4Tixc5mU-Pk
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies
*/


/************************************************************ C++ ************************************************************/
//Approach-1 - Brute Force
//T.C : O(n^2 * m)
//S.C : O(n+S)
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        int n = recipes.size();

        // Stores all recipes that can be prepared
        vector<string> result;

        // Stores all currently available items
        // (initial supplies + recipes prepared later)
        unordered_set<string> st(begin(supplies), end(supplies));

        // Keeps track of recipes that have already been prepared
        vector<bool> cooked(n, false);

        // Perform at most n passes since each pass can prepare
        // at least one new recipe
        int count = n;
        while(count--) {

            // Try preparing every recipe
            for(int j = 0; j < n; j++) {

                // Skip if this recipe is already prepared
                if(cooked[j]) {
                    continue;
                }

                // Assume all ingredients are available
                bool banpaega = true;

                // Check whether every ingredient is present
                for(int k = 0; k < ingredients[j].size(); k++) {
                    if(!st.count(ingredients[j][k])) {
                        // Missing ingredient, cannot prepare now
                        banpaega = false;
                        break;
                    }
                }

                // If all ingredients are available,
                // prepare this recipe
                if(banpaega) {

                    // Prepared recipe now becomes a new supply
                    st.insert(recipes[j]);

                    // Store the prepared recipe
                    result.push_back(recipes[j]);

                    // Mark it as prepared
                    cooked[j] = true;
                }
            }
        }

        return result;
    }
};