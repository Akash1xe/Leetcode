class Solution {
public:
    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& visited) {

        // Color the current node
        visited[node] = color;

        // Visit all neighbors
        for (int neighbor : graph[node]) {

            // If neighbor is not colored yet
            if (visited[neighbor] == 0) {

                // Give opposite color
                if (!dfs(neighbor, -color, graph, visited))
                    return false;
            }

            // Neighbor already colored
            else if (visited[neighbor] == color) {

                // Same color as current node
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        // 0 = unvisited
        // 1 = Color A
        // -1 = Color B
        vector<int> visited(n, 0);

        // Handle disconnected graph
        for (int i = 0; i < n; i++) {

            if (visited[i] == 0) {

                if (!dfs(i, 1, graph, visited))
                    return false;
            }
        }

        return true;
    }
};