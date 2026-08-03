class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (auto &edge : paths) {

            int u = edge[0] - 1;
            int v = edge[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // answer[i] = flower assigned to garden i
        vector<int> answer(n, 0);

        // Process every garden
        for (int garden = 0; garden < n; garden++) {

            // used[flower] = true if a neighbor already uses this flower
            bool used[5] = {false};

            // Mark flowers used by neighbors
            for (int neighbor : adj[garden]) {

                if (answer[neighbor] != 0)
                    used[answer[neighbor]] = true;
            }

            // Assign first available flower
            for (int flower = 1; flower <= 4; flower++) {

                if (!used[flower]) {

                    answer[garden] = flower;
                    break;
                }
            }
        }

        return answer;
    }
};