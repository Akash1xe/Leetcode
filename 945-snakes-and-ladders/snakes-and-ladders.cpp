class Solution {
public:
    int n;

    pair<int, int> getCoord(int square) {
        int row = (n - 1) - ((square - 1) / n);
        int col = (square - 1) % n;

        // Reverse direction for alternate rows
        if ((n % 2 == 0 && row % 2 == 0) ||
            (n % 2 == 1 && row % 2 == 1)) {
            col = n - 1 - col;
        }

        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {

        n = board.size();

        queue<int> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push(1);
        visited[n - 1][0] = true;   // Square 1

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int curr = q.front();
                q.pop();

                if (curr == n * n)
                    return steps;

                for (int dice = 1; dice <= 6; dice++) {

                    int next = curr + dice;

                    if (next > n * n)
                        break;

                    auto [row, col] = getCoord(next);

                    if (visited[row][col])
                        continue;

                    visited[row][col] = true;

                    if (board[row][col] == -1)
                        q.push(next);
                    else
                        q.push(board[row][col]);
                }
            }

            steps++;
        }

        return -1;
    }
};