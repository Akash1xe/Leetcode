/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=EA8dP63iVPk
    Company Tags                : Microsoft
    Leetcode Link               :
   https://leetcode.com/problems/longest-path-with-different-adjacent-characters/
    Similar Qn in Tree          : Binary Tree Maximum Path Sum - YouTube  :
   https://www.youtube.com/watch?v=Op6YFcs8R9M Leetcode :
   https://leetcode.com/problems/binary-tree-maximum-path-sum/
*/

// DFS - (Similar to Binary Tree Maximum Path Sum)
class Solution {
public:

    // Global answer: longest valid path anywhere in the tree
    int result;

    // Returns:
    // longest valid downward path starting from 'curr'
    int DFS(unordered_map<int, vector<int>>& adj,
            int curr,
            int parent,
            string& s) {

        // Best valid branch from curr
        int longest = 0;

        // Second-best valid branch from curr
        int second_longest = 0;

        // Explore all neighbors
        for (int& child : adj[curr]) {

            // Don't go back to parent
            if (child == parent)
                continue;

            // Ask child for its longest downward path
            int child_longest_length =
                DFS(adj, child, curr, s);

            // If curr and child have the same character,
            // this child branch CANNOT connect to curr.
            if (s[child] == s[curr])
                continue;

            // Keep the two largest valid child branches
            if (child_longest_length > second_longest)
                second_longest = child_longest_length;

            if (second_longest > longest)
                swap(longest, second_longest);
        }

        // Case 1:
        // Take the best ONE child branch + curr itself
        int one_branch =
            max(longest, second_longest) + 1;

        // Case 2:
        // Use only curr
        int only_curr = 1;

        // Case 3:
        // Path passes THROUGH curr using TWO child branches
        //
        // left branch + curr + right branch
        int path_through_curr =
            longest + second_longest + 1;

        // Update global answer
        result = max({
            result,
            one_branch,
            only_curr,
            path_through_curr
        });

        // Parent can continue through only ONE child branch.
        return max(one_branch, only_curr);
    }

    int longestPath(vector<int>& parent, string s) {

        int n = parent.size();

        result = 0;

        // Build undirected tree
        unordered_map<int, vector<int>> adj;

        for (int i = 1; i < n; i++) {

            int u = i;
            int v = parent[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Root the DFS at node 0
        DFS(adj, 0, -1, s);

        return result;
    }
};