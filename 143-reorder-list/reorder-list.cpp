class Solution {
public:
    void reorderList(ListNode* head) {

        // Edge case:
        // If there are 0, 1, or 2 nodes,
        // there is nothing meaningful to reorder.
        if (head == nullptr || head->next == nullptr) {
            return;
        }


        // --------------------------------------------------
        // STEP 1: Find the middle of the linked list
        // --------------------------------------------------

        ListNode* slow = head;
        ListNode* fast = head;

        // slow moves 1 step
        // fast moves 2 steps
        //
        // When fast reaches the end,
        // slow will be around the middle.
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is the last node of the first half.
        //
        // Example:
        //
        // 1 → 2 → 3 → 4 → 5
        //         ↑
        //        slow
        

        // --------------------------------------------------
        // STEP 2: Reverse the second half
        // --------------------------------------------------

        ListNode* second = slow->next;

        // Break the list into two separate halves.
        //
        // First half:
        // 1 → 2 → 3
        //
        // Second half:
        // 4 → 5
        //
        slow->next = nullptr;


        // Reverse second half:
        //
        // 4 → 5
        //
        // becomes:
        //
        // 5 → 4

        ListNode* prev = nullptr;
        ListNode* curr = second;

        while (curr != nullptr) {

            // Save next node before changing curr->next
            ListNode* nextNode = curr->next;

            // Reverse the pointer
            curr->next = prev;

            // Move prev forward
            prev = curr;

            // Move curr forward
            curr = nextNode;
        }

        // prev is now the head of reversed second half.
        second = prev;


        // --------------------------------------------------
        // STEP 3: Merge both halves alternately
        // --------------------------------------------------

        //
        // First half:
        // 1 → 2 → 3
        //
        // Second half:
        // 5 → 4
        //
        // We want:
        //
        // 1 → 5 → 2 → 4 → 3
        //

        ListNode* first = head;

        while (second != nullptr) {

            // Save next nodes because we are
            // going to change the links.
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;


            // Put second node after first node
            first->next = second;

            // Put next first-half node after second
            second->next = firstNext;


            // Move both pointers forward
            first = firstNext;
            second = secondNext;
        }
    }
};