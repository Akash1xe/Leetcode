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
    TreeNode *first = nullptr;
    TreeNode *middle = nullptr;
    TreeNode *last = nullptr;
    TreeNode *prev = nullptr;

    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;

        // Left
        inorder(root->left);

        // Violation found
        if (prev != nullptr && root->val < prev->val) {

            // First violation
            if (first == nullptr) {
                first = prev;
                middle = root;
            }
            // Second violation
            else {
                last = root;
            }
        }

        // Update previous node
        prev = root;

        // Right
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {

        inorder(root);

        // Non-adjacent swapped nodes
        if (first != nullptr && last != nullptr)
            swap(first->val, last->val);

        // Adjacent swapped nodes
        else if (first != nullptr && middle != nullptr)
            swap(first->val, middle->val);
    }
}; 