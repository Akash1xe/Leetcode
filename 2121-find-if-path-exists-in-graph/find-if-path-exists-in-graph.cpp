class Solution {
public:

    // Standard DFS
    void dfs(int node,
             vector<vector<int>>& adj,
             vector<bool>& visited) {

        // Mark current node as visited
        visited[node] = true;

        // Visit all neighbours
        for (int neighbour : adj[node]) {

            // Skip already visited nodes
            if (visited[neighbour])
                continue;

            dfs(neighbour, adj, visited);
        }
    }

    bool validPath(int n,
                   vector<vector<int>>& edges,
                   int source,
                   int destination) {

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            // Undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Visited array
        vector<bool> visited(n, false);

        // Start DFS from source
        dfs(source, adj, visited);

        // If destination is visited,
        // then a path exists.
        return visited[destination];
    }
};