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
    void preorder(TreeNode* root, int sum, int target,
                  vector<int>& path,
                  vector<vector<int>>& ans) {

        if (root == nullptr)
            return;

        // Process current node
        path.push_back(root->val);
        sum += root->val;

        // If it is a leaf and sum matches target
        if (root->left == nullptr &&
            root->right == nullptr &&
            sum == target) {

            ans.push_back(path);
        }

        // Traverse left subtree
        preorder(root->left, sum, target, path, ans);

        // Traverse right subtree
        preorder(root->right, sum, target, path, ans);

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        vector<int> path;

        preorder(root, 0, targetSum, path, ans);

        return ans;
    }
};