class FreqStack {
public:

    // freq[x] = current frequency of x
    unordered_map<int, int> freq;

    // group[f] = stack of elements whose frequency is f
    unordered_map<int, stack<int>> group;

    // Highest frequency currently present
    int maxFreq = 0;

    FreqStack() {
    }

    void push(int val) {

        // Increase frequency of val
        freq[val]++;

        // New frequency of val
        int f = freq[val];

        // Add val to the stack corresponding to
        // its new frequency.
        group[f].push(val);

        // Update maximum frequency
        maxFreq = max(maxFreq, f);
    }

    int pop() {

        // Get the most recently pushed element
        // among elements having maximum frequency.
        int val = group[maxFreq].top();

        // Remove it from that frequency stack.
        group[maxFreq].pop();

        // Its frequency decreases by one.
        freq[val]--;

        // If there are no elements left at maxFreq,
        // decrease maxFreq.
        if (group[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};

/*
Intuition:

This problem needs two things:

1. Frequency:
   We need to know how many times every number has appeared.

   freq[x] stores the frequency of x.

2. Recency:
   If two numbers have the same frequency, we need to
   remove the one that was pushed most recently.

   To handle this, group[f] is a stack containing elements
   that reached frequency f.

   Since group[f] is a stack, its top is automatically the
   most recently pushed element having frequency f.

For push(val):
    - Increase freq[val].
    - Put val into group[new_frequency].
    - Update maxFreq.

For pop():
    - Look at group[maxFreq].
    - Take its top element.
    - Decrease its frequency.
    - If that group becomes empty, decrease maxFreq.

This gives O(1) average time for both push() and pop().

Time Complexity:
O(1) average for push()
O(1) average for pop()

Space Complexity:
O(n)

where n is the number of elements pushed into the stack.
*/