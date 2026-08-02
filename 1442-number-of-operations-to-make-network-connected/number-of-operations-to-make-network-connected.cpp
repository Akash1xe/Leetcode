class Solution {
public:

    // DFS to visit all computers in the same connected component
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {

        // Mark current computer as visited
        vis[node] = 1;

        // Visit all directly connected computers
        for (int neighbor : adj[node]) {

            // If the neighbor is not visited yet,
            // continue DFS from there
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        // ----------------------------------------------------
        // A connected network of n computers needs at least
        // (n - 1) cables.
        //
        // If total cables are less than (n - 1),
        // it is impossible to connect all computers.
        // ----------------------------------------------------
        if (connections.size() < n - 1)
            return -1;

        // Adjacency list to represent the graph
        vector<vector<int>> adj(n);

        // Build the undirected graph
        for (auto &edge : connections) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Keeps track of visited computers
        vector<int> vis(n, 0);

        // Counts how many connected components exist
        int components = 0;

        // Visit every computer
        for (int i = 0; i < n; i++) {

            // If this computer hasn't been visited,
            // it starts a new connected component.
            if (!vis[i]) {

                components++;

                // Visit the entire component
                dfs(i, adj, vis);
            }
        }

        // If there are 'components' disconnected groups,
        // we need (components - 1) cables to connect them.
        return components - 1;
    }
};