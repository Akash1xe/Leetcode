class Solution {
public:
    // Returns true if the current node is safe
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {

        // If already processed, return whether it is safe
        if (state[node] != 0)
            return state[node] == 2;

        // Mark as currently visiting
        state[node] = 1;

        // Visit all neighbors
        for (int neigh : graph[node]) {

            // If neighbor is unsafe or forms a cycle
            if (!dfs(neigh, graph, state))
                return false;
        }

        // No cycle found from this node
        state[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, state))
                ans.push_back(i);
        }

        return ans;
    }
};