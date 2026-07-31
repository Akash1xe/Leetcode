class Solution {
public:

    // Step 1: Store the inorder traversal of the BST.
    // Since inorder traversal of a BST is always sorted,
    // the resulting vector will contain the node values in sorted order.
    void buildArr(vector<int>& inorder, TreeNode* root) {

        // Base case: If the current node is NULL, return.
        if (root == nullptr)
            return;

        // Visit the left subtree.
        buildArr(inorder, root->left);

        // Process the current node.
        inorder.push_back(root->val);

        // Visit the right subtree.
        buildArr(inorder, root->right);
    }

    // Step 2: Build a balanced BST from the sorted inorder array.
    TreeNode* buildBst(vector<int>& inorder, int left, int right) {

        // Base case:
        // If the current range is invalid, there is no node to create.
        if (left > right)
            return nullptr;

        // Find the middle element.
        // Choosing the middle ensures the tree remains balanced.
        int mid = left + (right - left) / 2;

        // Create the root node using the middle element.
        TreeNode* root = new TreeNode(inorder[mid]);

        // Recursively build the left subtree
        // using elements before the middle.
        root->left = buildBst(inorder, left, mid - 1);

        // Recursively build the right subtree
        // using elements after the middle.
        root->right = buildBst(inorder, mid + 1, right);

        // Return the root of the balanced subtree.
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {

        // Vector to store the sorted inorder traversal.
        vector<int> inorder;

        // Fill the vector with BST values in sorted order.
        buildArr(inorder, root);

        // Build and return the balanced BST
        // using the sorted inorder array.
        return buildBst(inorder, 0, inorder.size() - 1);
    }
};