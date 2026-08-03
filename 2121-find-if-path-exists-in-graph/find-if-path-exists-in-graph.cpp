class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        queue<int> q;

        q.push(source);
        visited[source] = true;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            // Destination found
            if (node == destination)
                return true;

            for (int neighbour : adj[node]) {

                if (visited[neighbour])
                    continue;

                visited[neighbour] = true;
                q.push(neighbour);
            }
        }

        return false;
    }
};