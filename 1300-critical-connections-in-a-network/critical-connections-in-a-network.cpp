class Solution {
private:
    void dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<int>& tin,
             vector<int>& low,
             vector<vector<int>>& bridges,
             int& timer) {

        tin[node] = low[node] = timer++;

        for (auto adjNode : adj[node]) {

            if (adjNode == parent) continue;

            if (tin[adjNode] == -1) {
                // Unvisited node
                dfs(adjNode, node, adj, tin, low, bridges, timer);

                low[node] = min(low[node], low[adjNode]);

                // Bridge condition
                if (low[adjNode] > tin[node]) {
                    bridges.push_back({node, adjNode});
                }
            }
            else {
                // Back edge
                low[node] = min(low[node], tin[adjNode]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(
        int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        // Build adjacency list
        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> tin(n, -1);
        vector<int> low(n, -1);

        vector<vector<int>> bridges;
        int timer = 0;

        // Handle disconnected components
        for (int i = 0; i < n; i++) {
            if (tin[i] == -1) {
                dfs(i, -1, adj, tin, low, bridges, timer);
            }
        }

        return bridges;
    }
};