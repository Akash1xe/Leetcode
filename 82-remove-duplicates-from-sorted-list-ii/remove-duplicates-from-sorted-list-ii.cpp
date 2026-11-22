class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* current = head;
        ListNode* prev = dummy;

        while (current != NULL) {

            if (current->next != NULL && current->val == current->next->val) {

                while (current->next != NULL && current->val == current->next->val) {
                    current = current->next;
                }

                prev->next = current->next;
            }
            else {
                prev = prev->next;
            }

            current = current->next;
        }

        return dummy->next;
    }
};