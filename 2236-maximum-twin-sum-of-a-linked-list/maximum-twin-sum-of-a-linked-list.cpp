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

class Solution {
public:
    int pairSum(ListNode* head) {

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow now points to the first node of the second half

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // prev = head of reversed second half

        // Step 3: Compare first half and reversed second half
        ListNode* left = head;
        ListNode* right = prev;

        int ans = 0;

        while (right != nullptr) {
            ans = max(ans, left->val + right->val);

            left = left->next;
            right = right->next;
        }

        return ans;
    }
};

/*
INTUITION:

For:
    4 -> 2 -> 2 -> 3

Twin pairs are:
    4 + 3
    2 + 2

The problem is that a singly linked list cannot move backward.

So:

1. Find the middle:
       4 -> 2 | 2 -> 3

2. Reverse the second half:
       4 -> 2
       3 -> 2

3. Now compare corresponding nodes:
       4 + 3 = 7
       2 + 2 = 4

4. Return the maximum = 7

TIME:  O(n)
SPACE: O(1)
*/