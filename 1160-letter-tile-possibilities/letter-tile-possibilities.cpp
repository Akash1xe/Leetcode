class Solution {
public:
    int count = 0;

    void solve(string &tiles, vector<bool> &used) {

        for (int i = 0; i < tiles.size(); i++) {

            // Already used in current sequence
            if (used[i]) continue;

            // Skip duplicate characters at same recursion level
            if (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1])
                continue;

            // Choose
            used[i] = true;
            count++;

            // Explore
            solve(tiles, used);

            // Backtrack
            used[i] = false;
        }
    }

    int numTilePossibilities(string tiles) {

        // Important for duplicate handling
        sort(tiles.begin(), tiles.end());

        vector<bool> used(tiles.size(), false);

        solve(tiles, used);

        return count;
    }
};