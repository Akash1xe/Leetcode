class Solution {
public:

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* doubleIt(ListNode* head) {

        // Step 1: Reverse the list
        // Example: 1 -> 2 -> 3
        // becomes: 3 -> 2 -> 1
        head = reverse(head);

        ListNode* curr = head;
        int carry = 0;

        // Step 2: Double each digit
        while (curr != nullptr) {

            int value = curr->val * 2 + carry;

            curr->val = value % 10;
            carry = value / 10;

            curr = curr->next;
        }

        // Step 3: If carry is left, create a new node
        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);

            curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }

            curr->next = newNode;
        }

        // Step 4: Reverse again to restore original order
        head = reverse(head);

        return head;
    }
};

/*
INTUITION:

The linked list stores a number digit by digit.

Example:
    1 -> 2 -> 9

means 129.

To multiply by 2, we must start from the rightmost digit:

    9 * 2 = 18
    digit = 8
    carry = 1

    2 * 2 + 1 = 5
    digit = 5
    carry = 0

    1 * 2 = 2
    digit = 2

Result:
    2 -> 5 -> 8

But a singly linked list cannot move backward.

Therefore:

    1 -> 2 -> 9
              ↓
    Reverse
              ↓
    9 -> 2 -> 1

Now we can process from left to right, which is
equivalent to processing the original list from right to left.

After doubling, reverse the list again.

TIME COMPLEXITY:
    O(n)

SPACE COMPLEXITY:
    O(1)

We only use a few pointer variables and modify the
existing linked list.
*/