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

            // Current element is <= target
            if (matrix[row][col] <= target) {

                // Because the column is sorted,
                // all elements from row 0 to current row
                // are also <= target.
                count += row + 1;

                // Check next column
                col++;
            }
            else {

                // Current value is too large,
                // move upward to get a smaller value.
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

        // Binary search on the answer
        while (low <= high) {

            int mid = low + (high - low) / 2;

            // How many elements are <= mid?
            int count = countLessEqual(matrix, mid);

            // We still don't have k elements,
            // so answer must be larger.
            if (count < k) {
                low = mid + 1;
            }

            // At least k elements are <= mid.
            // mid may be the answer, or answer may be smaller.
            else {
                high = mid - 1;
            }
        }

        // First value for which count >= k
        return low;
    }
};