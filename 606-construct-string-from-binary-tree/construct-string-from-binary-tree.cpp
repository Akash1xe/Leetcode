class Solution {
public:
    string tree2str(TreeNode* root) {

        if (root == NULL)
            return "";

        string result = to_string(root->val);

        string LEFT = tree2str(root->left);
        string RIGHT = tree2str(root->right);

        // Case 1: Leaf node
        if (root->left == NULL && root->right == NULL)
            return result;

        // Case 2: Only right child
        if (root->left == NULL)
            return result + "()" + "(" + RIGHT + ")";

        // Case 3: Only left child
        if (root->right == NULL)
            return result + "(" + LEFT + ")";

        // Case 4: Both children exist
        return result + "(" + LEFT + ")" + "(" +RIGHT + ")";
    }
};