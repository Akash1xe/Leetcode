/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    ListNode* curr;

    // Build BST for indices [left...right]
    TreeNode* build(int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        // Build left subtree first
        TreeNode* leftTree = build(left, mid - 1);

        // Current list node becomes root
        TreeNode* root = new TreeNode(curr->val);

        root->left = leftTree;

        // Move to next list node
        curr = curr->next;

        // Build right subtree
        root->right = build(mid + 1, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {

        // Count nodes
        int n = 0;
        ListNode* temp = head;

        while (temp) {
            n++;
            temp = temp->next;
        }

        curr = head;

        return build(0, n - 1);
    }
};