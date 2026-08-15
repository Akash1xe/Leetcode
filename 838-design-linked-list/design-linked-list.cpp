class MyLinkedList {
public:

    // Node structure
    struct Node {
        int val;
        Node* next;

        Node(int val) {
            this->val = val;
            this->next = nullptr;
        }
    };

    Node* head;
    int size;

    // Constructor
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    // Get the value of the node at given index
    int get(int index) {

        // If index is invalid, return -1
        if (index < 0 || index >= size)
            return -1;

        Node* curr = head;

        // Move curr to the required index
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->val;
    }

    // Add a new node at the beginning
    void addAtHead(int val) {

        Node* newNode = new Node(val);

        // New node points to current head
        newNode->next = head;

        // Make new node the head
        head = newNode;

        size++;
    }

    // Add a new node at the end
    void addAtTail(int val) {

        Node* newNode = new Node(val);

        // If list is empty, new node becomes head
        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }

        Node* curr = head;

        // Move to the last node
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        // Attach new node at the end
        curr->next = newNode;

        size++;
    }

    // Add a new node at the given index
    void addAtIndex(int index, int val) {

        // If index is greater than size,
        // insertion is not possible
        if (index > size)
            return;

        // If index is 0, insert at head
        if (index == 0) {
            addAtHead(val);
            return;
        }

        // If index is equal to size,
        // insert at tail
        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* curr = head;

        // Move to the node just before the index
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        Node* newNode = new Node(val);

        // Connect new node to the next node
        newNode->next = curr->next;

        // Connect previous node to new node
        curr->next = newNode;

        size++;
    }

    // Delete the node at the given index
    void deleteAtIndex(int index) {

        // If index is invalid, do nothing
        if (index < 0 || index >= size)
            return;

        // If deleting the head
        if (index == 0) {

            Node* temp = head;

            // Move head to the next node
            head = head->next;

            // Delete old head
            delete temp;

            size--;
            return;
        }

        Node* curr = head;

        // Move to the node just before the index
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        // Node that needs to be deleted
        Node* temp = curr->next;

        // Skip the node to be deleted
        curr->next = temp->next;

        // Free memory
        delete temp;

        size--;
    }
};

/*
===========================================================
INTUITION
===========================================================

We are implementing a singly linked list.

Each node contains:

    value
    next pointer

Example:

    10 -> 20 -> 30 -> 40 -> NULL


We maintain two important variables:

    head
    size

-----------------------------------------------------------
1. get(index)
-----------------------------------------------------------

We start from head and move index times.

Example:

    10 -> 20 -> 30 -> 40
              ^
            index 2

We return 30.

If index is invalid:

    index < 0
    OR
    index >= size

we return -1.

-----------------------------------------------------------
2. addAtHead(val)
-----------------------------------------------------------

To insert at the beginning:

Before:

    10 -> 20 -> 30

Insert 5.

First:

    newNode->next = head

So:

    5 -> 10 -> 20 -> 30

Then:

    head = newNode

Therefore insertion at head takes O(1).

-----------------------------------------------------------
3. addAtTail(val)
-----------------------------------------------------------

We need to reach the last node.

Example:

    10 -> 20 -> 30 -> NULL

curr moves:

    10
     ↓
    20
     ↓
    30

When:

    curr->next == NULL

we know curr is the last node.

Then:

    curr->next = newNode

Result:

    10 -> 20 -> 30 -> 40 -> NULL

-----------------------------------------------------------
4. addAtIndex(index, val)
-----------------------------------------------------------

For insertion in the middle, we need the node
BEFORE the required index.

Example:

    10 -> 20 -> 30 -> 40

Insert 25 at index 2.

Index:

     0     1     2     3
    10 -> 20 -> 30 -> 40

We stop at index 1:

    10 -> 20 -> 30 -> 40
          ^
        curr

Then perform:

    newNode->next = curr->next;
    curr->next = newNode;

Result:

    10 -> 20 -> 25 -> 30 -> 40

The important idea is:

    Find previous node
           ↓
    Connect new node
           ↓
    Connect new node to next node

-----------------------------------------------------------
5. deleteAtIndex(index)
-----------------------------------------------------------

Again, we find the node BEFORE the node we want to delete.

Example:

    10 -> 20 -> 30 -> 40

Delete index 2.

We stop at index 1:

    10 -> 20 -> 30 -> 40
          ^
        curr

The node to delete is:

    curr->next

So:

    temp = curr->next;

Then skip it:

    curr->next = temp->next;

Result:

    10 -> 20 -> 40

Finally:

    delete temp;

to free the memory.

-----------------------------------------------------------
CORE LINKED LIST IDEA
-----------------------------------------------------------

Insertion:

    Previous -> Next

becomes:

    Previous -> NewNode -> Next


Deletion:

    Previous -> DeleteNode -> Next

becomes:

    Previous ----------------> Next


So the main skill in this problem is learning how to
correctly manipulate the `next` pointers.

===========================================================
*/