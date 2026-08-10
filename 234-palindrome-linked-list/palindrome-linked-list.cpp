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
    bool isPalindrome(ListNode* head) {

        // If the list is empty or has only one node,
        // it is automatically a palindrome.
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // slow moves one step at a time
        // fast moves two steps at a time
        //
        // When fast reaches the end,
        // slow will be around the middle of the list.
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is now at the beginning of the second half.
        //
        // Example:
        // 1 -> 2 -> 2 -> 1
        //         ^
        //        slow

        // Reverse the second half of the linked list.
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr != nullptr) {

            // Save the next node before changing the link.
            ListNode* nextTemp = curr->next;

            // Reverse the current node's pointer.
            curr->next = prev;

            // Move prev and curr forward.
            prev = curr;
            curr = nextTemp;
        }

        // prev is now the head of the reversed second half.
        //
        // Example:
        // Original second half:
        // 2 -> 1
        //
        // After reversal:
        // 1 -> 2
        //
        // prev
        //  ↓
        // 1 -> 2

        // p1 starts from the beginning of the list.
        // p2 starts from the reversed second half.
        ListNode* p1 = head;
        ListNode* p2 = prev;

        // Compare both halves node by node.
        while (p2 != nullptr) {

            // If values don't match,
            // the linked list cannot be a palindrome.
            if (p1->val != p2->val) {
                return false;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        // Every corresponding value matched.
        return true;
    }
};


/*
===========================================================
INTUITION
===========================================================

A palindrome reads the same from both directions.

Example:

    1 -> 2 -> 2 -> 1

If we could compare:

    First half:              1 -> 2
    Second half backwards:   1 -> 2

then we can easily determine whether the list is a palindrome.

But a linked list does not allow us to move backwards.

So we use this idea:

1. Find the middle of the linked list
   using slow and fast pointers.

       slow -> 1 step
       fast -> 2 steps

   When fast reaches the end,
   slow reaches the middle.

2. Reverse the second half.

       Before:
       1 -> 2 -> 2 -> 1

       Second half:
             2 -> 1

       After reversing:
             1 -> 2

3. Now compare the first half with the reversed second half.

       First half:
       1 -> 2

       Reversed second half:
       1 -> 2

       1 == 1  ✓
       2 == 2  ✓

       Therefore it is a palindrome.

-----------------------------------------------------------

WHY DO WE ONLY COMPARE p2?

After reversing the second half, p2 represents
the entire second half.

For an even-length list:

       1 -> 2 -> 2 -> 1
       ^       ^
       p1     p2

Both halves have the same number of nodes.

For an odd-length list, there is a middle node
which does not need to be compared with anything.

Example:

       1 -> 2 -> 3 -> 2 -> 1

The middle node is 3.

We only need to compare:

       1 with 1
       2 with 2

The middle element can be ignored.

-----------------------------------------------------------

TIME COMPLEXITY:

Finding middle       -> O(n)
Reversing half       -> O(n)
Comparing halves     -> O(n)

Overall              -> O(n)

SPACE COMPLEXITY:

We only use a few pointers.

Overall              -> O(1)

===========================================================
*/