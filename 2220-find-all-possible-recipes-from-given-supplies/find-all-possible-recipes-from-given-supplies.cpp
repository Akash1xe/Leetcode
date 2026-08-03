//Approach-2 - Using Topological Sorting
//T.C : O(n + m + S)
//S.C : O(n + S)
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        int n = recipes.size();

        // Stores all initially available supplies
        unordered_set<string> st(begin(supplies), end(supplies));

        // Adjacency List
        // ingredient -> list of recipes that depend on it
        unordered_map<string, vector<int>> adj;


        // indegree[i] = number of ingredients of recipe i
        // that are not initially available
        vector<int> indegree(n, 0);

        // Build the graph
        for(int i = 0; i < n; i++) {
            for(string& ing : ingredients[i]) {

                // Ignore ingredients that are already available
                if(!st.count(ing)) {

                    // This ingredient is required for recipe i
                    adj[ing].push_back(i);

                    // One more dependency for recipe i
                    indegree[i]++;
                }
            }
        }

        // Stores all recipes that can currently be prepared
        queue<int> que;

        // Recipes with no missing ingredients
        // can be prepared immediately
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<string> result;

        // Standard Kahn's Algorithm (Topological Sort)
        while(!que.empty()) {

            // Current recipe that can be prepared
            int i = que.front();
            que.pop();

            string recipe = recipes[i];

            // Add to the answer
            result.push_back(recipe);

            // This recipe now acts as an ingredient
            // for other recipes depending on it
            for(int &idx : adj[recipe]) {

                // One dependency has been satisfied
                indegree[idx]--;

                // All dependencies satisfied
                if(indegree[idx] == 0) {
                    que.push(idx);
                }
            }
        }

        return result;
    }
};