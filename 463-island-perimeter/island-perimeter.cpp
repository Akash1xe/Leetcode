class Solution {
public:

    int dfs(vector<vector<int>>& grid, int r, int c) {

        int m = grid.size();
        int n = grid[0].size();


        // If we go outside the grid
        // this side contributes to perimeter
        if(r < 0 || c < 0 || r >= m || c >= n) {
            return 1;
        }


        // If we hit water
        // this side contributes to perimeter
        if(grid[r][c] == 0) {
            return 1;
        }


        // Already visited land
        // shared side, so no contribution
        if(grid[r][c] == -1) {
            return 0;
        }


        // Mark current land cell as visited
        grid[r][c] = -1;


        int perimeter = 0;


        // 4 directions
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};


        // Explore all 4 neighbours
        for(int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            perimeter += dfs(grid, nr, nc);
        }


        return perimeter;
    }



    int islandPerimeter(vector<vector<int>>& grid) {


        int m = grid.size();
        int n = grid[0].size();


        // Find first land cell
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {


                if(grid[i][j] == 1) {

                    return dfs(grid, i, j);
                }
            }
        }


        return 0;
    }
};