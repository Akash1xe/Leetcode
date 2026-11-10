class Solution {
public:

    // DFS function to explore all possible paths
    void dfs(int node, vector<vector<int>>& ans, vector<vector<int>>& graph,
             vector<int>& path) {

        // Add current node to the current path
        path.push_back(node);

        // If we reached the target node (last node)
        if (node == graph.size() - 1) {

            // Store the complete path in the answer
            ans.push_back(path);
        }

        // Traverse all neighbors of the current node
        for (auto neig : graph[node]) {

            // Recursively visit the neighbor
            dfs(neig, ans, graph, path);
        }

        // Backtrack: remove current node before returning
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        // Stores all valid paths from source to target
        vector<vector<int>> ans;

        // Stores the current path being explored
        vector<int> path;

        // Start DFS from node 0 (source)
        dfs(0, ans, graph, path);

        // Return all discovered paths
        return ans;
    }
};