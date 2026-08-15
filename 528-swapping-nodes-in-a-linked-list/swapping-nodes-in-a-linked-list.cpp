class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        // Step 1: Move fast to the kth node from the beginning
        ListNode* fast = head;

        for (int i = 1; i < k; i++) {
            fast = fast->next;
        }

        // Save the kth node from the beginning
        ListNode* first = fast;

        // Step 2: Start slow from head
        ListNode* slow = head;

        // Move fast and slow together
        // When fast reaches the last node,
        // slow will be kth node from the end
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // kth node from the end
        ListNode* second = slow;

        // Step 3: Swap only the values
        swap(first->val, second->val);

        return head;
    }
};