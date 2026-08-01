class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<bool> visited(n, false);

        int provinces = 0;

        for (int i = 0; i < n; i++) {

            // New province found
            if (!visited[i]) {

                provinces++;

                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {

                    int node = q.front();
                    q.pop();

                    // Traverse all neighbours
                    for (int neighbour = 0; neighbour < n; neighbour++) {

                        if (isConnected[node][neighbour] == 1 &&
                            !visited[neighbour]) {

                            visited[neighbour] = true;
                            q.push(neighbour);
                        }
                    }
                }
            }
        }

        return provinces;
    }
};