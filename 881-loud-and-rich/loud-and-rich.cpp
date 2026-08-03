class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        int n = quiet.size();

        // Graph: Rich -> Poor
        vector<vector<int>> graph(n);

        // Indegree for Kahn's algorithm
        vector<int> indegree(n, 0);

        // Build graph
        for (auto &edge : richer) {
            int rich = edge[0];
            int poor = edge[1];

            graph[rich].push_back(poor);
            indegree[poor]++;
        }

        // answer[i] = quietest richer (or equal) person for i
        vector<int> answer(n);

        // Initially every person's answer is themselves
        for (int i = 0; i < n; i++)
            answer[i] = i;

        queue<int> q;

        // Richest people (indegree = 0)
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Kahn's Topological Sort
        while (!q.empty()) {

            int u = q.front();
            q.pop();

            // Update all poorer people
            for (int v : graph[u]) {

                // If u's best candidate is quieter than v's best candidate,
                // update v's answer.
                if (quiet[answer[u]] < quiet[answer[v]]) {
                    answer[v] = answer[u];
                }

                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        return answer;
    }
};