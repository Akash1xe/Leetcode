class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> dist(n, INT_MAX);
        vector<int> vis(n, 0);

        dist[0] = 0;

        int ans = 0;

        for (int i = 0; i < n; i++) {

            int node = -1;

            // Find the unvisited node with minimum distance
            for (int j = 0; j < n; j++) {
                if (!vis[j] && (node == -1 || dist[j] < dist[node])) {
                    node = j;
                }
            }

            vis[node] = 1;
            ans += dist[node];

            // Update distances of remaining nodes
            for (int j = 0; j < n; j++) {

                if (!vis[j]) {
                    int cost = abs(points[node][0] - points[j][0])
                             + abs(points[node][1] - points[j][1]);

                    dist[j] = min(dist[j], cost);
                }
            }
        }

        return ans;
    }
};