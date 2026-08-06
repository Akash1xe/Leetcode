class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        // If the first node of the first edge is present
        // in the second edge, it is the center.
        if (edges[0][0] == edges[1][0] ||
            edges[0][0] == edges[1][1])
            return edges[0][0];

        // Otherwise, the second node of the first edge
        // must be the center.
        return edges[0][1];
    }
};