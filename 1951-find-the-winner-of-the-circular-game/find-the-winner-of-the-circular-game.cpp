class Solution {
public:
    int func(int n, int k) {

        // Only one person remains
        if (n == 1)
            return 0;   // 0-based position

        // Find winner among n-1 people
        int winner = func(n - 1, k);

        // Shift the winner's position because
        // every round starts after the eliminated person
        return (winner + k) % n;
    }

    int findTheWinner(int n, int k) {

        // func() gives 0-based answer
        // +1 converts it to 1-based person number
        return func(n, k) + 1;
    }
};