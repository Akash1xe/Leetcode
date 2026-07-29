class Solution {
public:
    void inorder(TreeNode* root, vector<int>& sorted) {
        if (root == nullptr)
            return;

        inorder(root->left, sorted);
        sorted.push_back(root->val);
        inorder(root->right, sorted);
    }

    void compare(TreeNode* root, vector<int>& sorted, int &idx) {
        if (root == nullptr)
            return;

        compare(root->left, sorted, idx);

        root->val = sorted[idx++];
        
        compare(root->right, sorted, idx);
    }

    void recoverTree(TreeNode* root) {

        vector<int> sorted;

        inorder(root, sorted);

        sort(sorted.begin(), sorted.end());

        int idx = 0;
        compare(root, sorted, idx);
    }
};