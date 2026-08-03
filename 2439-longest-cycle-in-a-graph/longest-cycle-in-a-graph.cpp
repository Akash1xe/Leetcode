class Solution {
public:
    int longestCycle(vector<int>& edges) {

        int n = edges.size();

        // Marks whether a node has been processed globally
        vector<bool> visited(n, false);

        int answer = -1;

        // Try starting from every node
        for (int start = 0; start < n; start++) {

            // Already processed
            if (visited[start])
                continue;

            // Stores:
            // node -> step number
            unordered_map<int, int> position;

            int node = start;
            int step = 0;

            // Walk until graph ends
            // or reaches a processed node
            while (node != -1 && !visited[node]) {

                visited[node] = true;

                position[node] = step++;

                node = edges[node];
            }

            // If node belongs to current path,
            // we found a cycle.
            if (node != -1 && position.count(node)) {

                answer = max(answer,
                             step - position[node]);
            }
        }

        return answer;
    }
};