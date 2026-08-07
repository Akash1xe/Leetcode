class Solution {
public:
    // DFS function to traverse and recolor the connected component
    void dfs(int r, int c,
             vector<vector<int>>& image,
             int initialColor,
             int newColor,
             vector<int>& delRow,
             vector<int>& delCol) {

        int n = image.size();
        int m = image[0].size();

        // Change the color of the current cell
        image[r][c] = newColor;

        // Traverse all 4 directions
        for (int i = 0; i < 4; i++) {

            // Calculate new row and column
            int newRow = r + delRow[i];
            int newCol = c + delCol[i];

            // Check:
            // 1. Boundary conditions
            // 2. Cell has the initial color
            // 3. Cell is not already recolored
            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < m &&
                image[newRow][newCol] == initialColor &&
                image[newRow][newCol] != newColor) {

                dfs(newRow, newCol, image,
                    initialColor, newColor,
                    delRow, delCol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();

        // Color of the starting cell
        int initialColor = image[sr][sc];

        // Direction arrays for Right, Down, Left, Up
        vector<int> delRow = {0, 1, 0, -1};
        vector<int> delCol = {1, 0, -1, 0};

        // Only run DFS if the new color is different
        if (initialColor != color) {
            dfs(sr, sc, image,
                initialColor, color,
                delRow, delCol);
        }

        return image;
    }
};