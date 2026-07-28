/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = {};
    }

    Node(int _val) {
        val = _val;
        neighbors = {};
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {

        // Empty graph
        if (node == nullptr)
            return nullptr;

        // Already cloned
        if (mp.count(node))
            return mp[node];

        // Create clone
        Node* clone = new Node(node->val);

        // Store mapping
        mp[node] = clone;

        // Clone neighbours
        for (Node* nbr : node->neighbors) {
            clone->neighbors.push_back(dfs(nbr));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};