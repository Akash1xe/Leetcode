/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        // Case 1:
        // If the new row is to be added at depth 1,
        // create a new root and attach the original tree
        // as its left child.
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        // Queue for Level Order Traversal (BFS)
        queue<TreeNode*> q;
        q.push(root);

        // Root is at depth 1
        int currentDepth = 1;

        while (!q.empty()) {

            // Number of nodes present at the current level
            int size = q.size();

            // If we've reached the level just above the target depth,
            // insert the new row below every node at this level.
            if (currentDepth == depth - 1) {

                while (size--) {

                    TreeNode* node = q.front();
                    q.pop();

                    // Create new left and right nodes
                    TreeNode* newLeft = new TreeNode(val);
                    TreeNode* newRight = new TreeNode(val);

                    // Attach the original left subtree
                    // below the newly created left node.
                    newLeft->left = node->left;

                    // Attach the original right subtree
                    // below the newly created right node.
                    newRight->right = node->right;

                    // Connect the new nodes to the current node.
                    node->left = newLeft;
                    node->right = newRight;
                }

                // Tree modification is complete.
                break;
            }

            // Traverse the current level
            while (size--) {

                TreeNode* node = q.front();
                q.pop();

                // Push left child if it exists
                if (node->left)
                    q.push(node->left);

                // Push right child if it exists
                if (node->right)
                    q.push(node->right);
            }

            // Move to the next level
            currentDepth++;
        }

        return root;
    }
};