/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Returns the height of the subtree.
    // If the subtree is not balanced, returns -1.
    int dfsHeight(TreeNode* root) {
        // Base case: Empty tree has height 0
        if (root == nullptr)
            return 0;

        // Find height of left subtree
        int leftHeight = dfsHeight(root->left);

        // If left subtree is unbalanced, propagate -1
        if (leftHeight == -1)
            return -1;

        // Find height of right subtree
        int rightHeight = dfsHeight(root->right);

        // If right subtree is unbalanced, propagate -1
        if (rightHeight == -1)
            return -1;

        // Current node is unbalanced
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        // Return height of current subtree
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1 ;
    }
};

/*
Intuition:
----------
A binary tree is balanced if, for every node,
the height difference between its left and right subtree is at most 1.

Instead of calculating the height separately for every node
(which would take O(N^2) time), we combine both tasks in one DFS.

1. Recursively compute the height of the left subtree.
2. Recursively compute the height of the right subtree.
3. If either subtree is already unbalanced, immediately return -1.
4. If the height difference is greater than 1, return -1.
5. Otherwise, return the height of the current subtree.

The value -1 acts as a special flag indicating that some subtree
is already unbalanced, allowing us to stop unnecessary computation.

Time Complexity: O(N)
- Every node is visited exactly once.

Space Complexity: O(H)
- H is the height of the tree (recursive stack).
- Worst case: O(N) for a skewed tree.
- Best/Average case: O(log N) for a balanced tree.
*/