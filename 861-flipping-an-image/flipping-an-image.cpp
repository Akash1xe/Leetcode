class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m = image.size();
        int n = image[0].size();

        // Step 1: Reverse every row
        for (int i = 0; i < m; i++) {
            reverse(image[i].begin(), image[i].end());
        }

        // Step 2: Invert every element
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                image[i][j] = 1 - image[i][j];
            }
        }

        return image;
    }
};