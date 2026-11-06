class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty())
            return {};

        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans;

        int row = 0, col = 0;
        bool up = true;

        while (ans.size() < m * n) {

            ans.push_back(mat[row][col]);

            if (up) {

                // Reached the right boundary
                if (col == n - 1) {
                    row++;
                    up = false;
                }

                // Reached the top boundary
                else if (row == 0) {
                    col++;
                    up = false;
                }

                // Move up-right
                else {
                    row--;
                    col++;
                }
            }

            else {

                // Reached the bottom boundary
                if (row == m - 1) {
                    col++;
                    up = true;
                }

                // Reached the left boundary
                else if (col == 0) {
                    row++;
                    up = true;
                }

                // Move down-left
                else {
                    row++;
                    col--;
                }
            }
        }

        return ans;
    }
};