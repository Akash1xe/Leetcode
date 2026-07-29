class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr)
            return root->val == targetSum;

        bool left = hasPathSum(root->left, targetSum - root->val);
        bool right = hasPathSum(root->right, targetSum - root->val);

        return left || right;
    }
};