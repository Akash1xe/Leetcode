class Solution {
public:

    // Count how many elements in the matrix are <= target
    int countLessEqual(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();

        // Start from bottom-left
        int row = n - 1;
        int col = 0;

        int count = 0;

        while (row >= 0 && col < n) {

            // If current value <= target,
            // then all elements above it in this column are also <= target
            if (matrix[row][col] <= target) {

                count += row + 1;

                // Move right to check next column
                col++;
            }
            else {
                // Current value is too large,
                // move up to get a smaller value
                row--;
            }
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        // Smallest possible answer
        int low = matrix[0][0];

        // Largest possible answer
        int high = matrix[n - 1][n - 1];

        // We are finding the first value such that:
        // count(elements <= value) >= k
        while (low <= high) {

            int mid = low + (high - low) / 2;

            int count = countLessEqual(matrix, mid);

            // Enough elements are <= mid
            // So answer can be mid or smaller
            if (count >= k) {
                high = mid-1;
            }

            // Not enough elements are <= mid
            // So kth smallest must be greater than mid
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};