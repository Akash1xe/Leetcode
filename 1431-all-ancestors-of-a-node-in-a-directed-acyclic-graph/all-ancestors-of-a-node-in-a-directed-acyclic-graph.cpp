class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        // Adjacency list
        vector<vector<int>> graph(n);

        // Indegree of every node
        vector<int> indegree(n, 0);

        // Build graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            indegree[v]++;
        }

        // ancestors[i] stores all ancestors of node i
        vector<set<int>> ancestors(n);

        queue<int> q;

        // Start with source nodes
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Kahn's Algorithm
        while (!q.empty()) {

            int u = q.front();
            q.pop();

            // Process every child
            for (int v : graph[u]) {

                // Current node is an ancestor of its child
                ancestors[v].insert(u);

                // All ancestors of u are also ancestors of v
                ancestors[v].insert(ancestors[u].begin(), ancestors[u].end());

                // Reduce indegree
                indegree[v]--;

                // Child becomes ready
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        // Convert sets into vectors
        vector<vector<int>> answer(n);

        for (int i = 0; i < n; i++) {
            answer[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return answer;
    }
};