class Solution {
public:

    // Stores the total fuel required across all edges
    long long fuel = 0;

    // Returns the number of people in the subtree of 'node'
    int dfs(vector<vector<int>>& graph,
            int node,
            int parent,
            int seats) {

        // Every city has one representative
        int people = 1;

        // Visit all neighboring cities
        for (int child : graph[node]) {

            // Don't go back to the parent
            if (child == parent)
                continue;

            // Get the number of representatives
            // present in this child's subtree
            int childPeople =
                dfs(graph, child, node, seats);

            // All representatives from the child's subtree
            // must travel through the edge child -> node.
            //
            // One car can carry 'seats' people, so the number
            // of cars needed is ceil(childPeople / seats).
            //
            // ceil(a / b) = (a + b - 1) / b
            fuel +=
                (childPeople + seats - 1) / seats;

            // Add the child's representatives to
            // the current node's total
            people += childPeople;
        }

        // Return total representatives in this subtree
        return people;
    }

    long long minimumFuelCost(
        vector<vector<int>>& roads,
        int seats) {

        // There are n - 1 roads for n cities
        int n = roads.size() + 1;

        // Build adjacency list
        vector<vector<int>> graph(n);

        // Since roads are undirected, add both directions
        for (auto& road : roads) {

            int u = road[0];
            int v = road[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Start DFS from the capital (city 0).
        // -1 means city 0 has no parent.
        dfs(graph, 0, -1, seats);

        // Return the minimum total fuel
        return fuel;
    }
};