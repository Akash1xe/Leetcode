class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // Dummy node is placed before head.
        // This helps us handle deletion of the first node
        // without writing a separate special case.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;

        while (curr->next != nullptr) {

            // If the next node contains the value to remove
            if (curr->next->val == val) {

                // Skip the node
                curr->next = curr->next->next;
            }
            else {
                // Move forward only when we don't delete
                curr = curr->next;
            }
        }

        // The actual head is after dummy
        return dummy->next;
    }
};