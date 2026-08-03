class Solution {
public:

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        // Build adjacency list
        vector<vector<int>> adj(n + 1);

        for (auto &edge : dislikes) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // -1 = uncolored
        // 0 = Group A
        // 1 = Group B
        vector<int> color(n + 1, -1);

        // Graph may be disconnected
        for (int start = 1; start <= n; start++) {

            if (color[start] != -1)
                continue;

            queue<int> q;
            q.push(start);

            color[start] = 0;

            while (!q.empty()) {

                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {

                    // Assign opposite color
                    if (color[neighbor] == -1) {

                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }

                    // Same color on adjacent nodes
                    else if (color[neighbor] == color[node]) {

                        return false;
                    }
                }
            }
        }

        return true;
    }
};