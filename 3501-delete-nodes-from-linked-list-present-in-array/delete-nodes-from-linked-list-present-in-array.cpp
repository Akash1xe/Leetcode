class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        // Store all values that need to be deleted
        unordered_set<int> st;

        for (int x : nums) {
            st.insert(x);
        }

        // Dummy node handles deletion of the head easily
        ListNode dummy(0);
        dummy.next = head;

        ListNode* curr = &dummy;

        while (curr->next != nullptr) {

            // If the next node's value is present in nums
            if (st.count(curr->next->val)) {

                // Delete the next node
                curr->next = curr->next->next;

            } else {

                // Move forward only when we keep the next node
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};