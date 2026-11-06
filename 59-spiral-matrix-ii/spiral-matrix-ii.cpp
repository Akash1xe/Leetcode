class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;

        int num = 1;

        while (top <= bottom && left <= right) {

            // 1. Left to Right
            for (int j = left; j <= right; j++) {
                ans[top][j] = num++;
            }
            top++;

            // 2. Top to Bottom
            for (int i = top; i <= bottom; i++) {
                ans[i][right] = num++;
            }
            right--;

            // 3. Right to Left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans[bottom][j] = num++;
                }
                bottom--;
            }

            // 4. Bottom to Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][left] = num++;
                }
                left++;
            }
        }

        return ans;
    }
};