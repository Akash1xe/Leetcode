class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {

            // Find GCD of current node and next node
            int g = __gcd(curr->val, curr->next->val);

            // Create a new node containing the GCD
            ListNode* newNode = new ListNode(g);

            // Insert newNode between curr and curr->next
            newNode->next = curr->next;
            curr->next = newNode;

            // Move to the original next node
            curr = newNode->next;
        }

        return head;
    }
};