/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=m6cp4eHWLak
    Company Tags                : <soon>
    Leetcode Link               : https://leetcode.com/problems/longest-cycle-in-a-graph/
*/

// Using DFS
// Idea:
// 1. Traverse every unvisited node using DFS.
// 2. Maintain:
//      - visited      -> Node has been processed before.
//      - inRecursion  -> Node is part of the current DFS path.
//      - dist         -> DFS depth of each node.
// 3. If we reach a node already present in the current recursion stack,
//    then a cycle is found.
// 4. Cycle length = current depth - depth of repeated node + 1.

class Solution {
public:
    // Stores the maximum cycle length found
    int result = -1;

    void dfs(int u,
             vector<int>& edges,
             vector<bool>& visited,
             vector<int>& dist,
             vector<bool>& inRecursion) {

        // Ignore invalid node (-1 means no outgoing edge)
        if (u != -1) {

            // Mark current node as visited
            visited[u] = true;

            // Add current node into recursion stack
            inRecursion[u] = true;

            // Every node has at most one outgoing edge
            int v = edges[u];

            // If next node exists and is not visited,
            // continue DFS
            if (v != -1 && !visited[v]) {

                // Store DFS depth of next node
                dist[v] = dist[u] + 1;

                dfs(v, edges, visited, dist, inRecursion);

            }

            // If next node is already in current DFS path,
            // then a directed cycle is found
            else if (v != -1 && inRecursion[v]) {

                // Cycle Length =
                // Current Depth - Previous Depth + 1
                result = max(result, dist[u] - dist[v] + 1);
            }

            // Backtracking:
            // Remove current node from recursion stack
            inRecursion[u] = false;
        }
    }

    int longestCycle(vector<int>& edges) {

        int n = edges.size();

        // Marks nodes already completely processed
        vector<bool> visited(n, false);

        // Stores DFS depth of every node
        vector<int> dist(n, 1);

        // Marks nodes currently present in recursion stack
        vector<bool> inRecursion(n, false);

        // Start DFS from every unvisited node
        for (int i = 0; i < n; i++) {

            if (!visited[i]) {
                dfs(i, edges, visited, dist, inRecursion);
            }
        }

        // Return maximum cycle length found
        return result;
    }
};