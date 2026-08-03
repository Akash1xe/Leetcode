class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {

        // ---------------- Build Graph ----------------
        // Adjacency list for the undirected graph
        vector<vector<int>> adj(n);

        // Add both directions because the graph is undirected
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Stores the length of the shortest cycle found so far
        int shortestCycle = INT_MAX;

        // --------------------------------------------------
        // Run BFS from every node
        // Every BFS treats 'start' as the source and computes
        // the shortest distance from it to all other nodes.
        // --------------------------------------------------
        for (int start = 0; start < n; start++) {

            // distance[i] = shortest distance from 'start' to node i
            // -1 means not visited yet
            vector<int> distance(n, -1);

            // parent[i] = node from which i was discovered
            // Used to ignore the immediate reverse edge
            vector<int> parent(n, -1);

            queue<int> q;

            // Begin BFS
            q.push(start);
            distance[start] = 0;

            while (!q.empty()) {

                int node = q.front();
                q.pop();

                // Explore all adjacent vertices
                for (int neighbor : adj[node]) {

                    // --------------------------------------------------
                    // Case 1 : First time visiting this neighbor
                    // --------------------------------------------------
                    if (distance[neighbor] == -1) {

                        // Update shortest distance
                        distance[neighbor] = distance[node] + 1;

                        // Store parent to avoid considering
                        // the direct reverse edge as a cycle
                        parent[neighbor] = node;

                        q.push(neighbor);
                    }

                    // --------------------------------------------------
                    // Case 2 : Neighbor already visited
                    // If it is NOT the parent, then we found a cycle.
                    // Cycle Length =
                    // distance[node] + distance[neighbor] + 1
                    // --------------------------------------------------
                    else if (parent[node] != neighbor) {

                        shortestCycle = min(shortestCycle,
                                            distance[node] +
                                            distance[neighbor] +
                                            1);
                    }
                }
            }
        }

        // If no cycle was found, return -1
        return shortestCycle == INT_MAX ? -1 : shortestCycle;
    }
};