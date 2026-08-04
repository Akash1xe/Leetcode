class Solution {
public:

    // Returns true if a cycle is found starting from 'node'
    bool dfsCheck(int node,
                  vector<vector<int>>& graph,
                  vector<int>& vis,
                  vector<int>& pathVis,
                  vector<int>& check) {

        // Mark the current node as visited
        vis[node] = 1;

        // Mark the node as part of the current DFS path
        pathVis[node] = 1;

        // Assume the node is unsafe initially
        // It will be marked safe only if no cycle is found
        check[node] = 0;

        // Traverse all adjacent nodes
        for (int neigh : graph[node]) {

            // If the neighbor has not been visited
            if (!vis[neigh]) {

                // If a cycle is found from the neighbor,
                // propagate the result upward
                if (dfsCheck(neigh, graph, vis, pathVis, check)==true)
                    return true;
            }

            // If the neighbor is already in the current DFS path,
            // then we have detected a cycle
            else if (pathVis[neigh]) {
                return true;
            }
        }

        // No cycle was found from this node,
        // so mark it as a safe node
        check[node] = 1;

        // Remove the node from the current DFS path
        // because backtracking is happening
        pathVis[node] = 0;

        // Return false because no cycle exists
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();

        // vis[i] = 1 -> node has already been visited
        vector<int> vis(V, 0);

        // pathVis[i] = 1 -> node is currently in the recursion stack
        vector<int> pathVis(V, 0);

        // check[i] = 1 -> node is safe
        // check[i] = 0 -> node is unsafe
        vector<int> check(V, 0);

        vector<int> safeNodes;

        // Run DFS from every unvisited node
        // to cover disconnected components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }

        // Collect all nodes marked as safe
        for (int i = 0; i < V; i++) {
            if (check[i] == 1)
                safeNodes.push_back(i);
        }

        return safeNodes;
    }
};