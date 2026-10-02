class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        int groupSize = 1;

        while (curr) {

            // Find the actual size of current group
            ListNode* temp = curr;
            int size = 0;

            while (temp && size < groupSize) {
                temp = temp->next;
                size++;
            }

            // Reverse only if the group size is even
            if (size % 2 == 0) {

                ListNode* groupPrev = prev;
                ListNode* groupCurr = curr;

                for (int i = 0; i < size; i++) {
                    ListNode* next = groupCurr->next;
                    groupCurr->next = groupPrev;
                    groupPrev = groupCurr;
                    groupCurr = next;
                }

                // Connect previous group to reversed group
                if (prev)
                    prev->next = groupPrev;

                // curr is now the last node of the reversed group
                curr->next = groupCurr;

                // Move prev to the end of current group
                prev = curr;
                curr = groupCurr;

            } else {

                // Odd-sized group: don't reverse
                for (int i = 0; i < size; i++) {
                    prev = curr;
                    curr = curr->next;
                }
            }

            groupSize++;
        }

        return head;
    }
};