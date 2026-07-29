class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr)
            return 0;

        // Current value is too small
        if (root->val < low)
            return rangeSumBST(root->right, low, high);

        // Current value is too large
        if (root->val > high)
            return rangeSumBST(root->left, low, high);

        // Current value lies in the range
        return root->val +
               rangeSumBST(root->left, low, high) +
               rangeSumBST(root->right, low, high);
    }
};