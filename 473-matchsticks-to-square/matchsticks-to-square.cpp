class Solution {
public:

    bool isValid(int ind, vector<int>& matchsticks,
                 vector<int>& sides, int target) {

        // All matchsticks have been placed
        if (ind == matchsticks.size()) {
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target &&
                   sides[3] == target;
        }

        // Try putting current matchstick on each of 4 sides
        for (int i = 0; i < 4; i++) {

            // Cannot exceed target side length
            if (sides[i] + matchsticks[ind] > target)
                continue;

            // Choose
            sides[i] += matchsticks[ind];

            // Explore
            if (isValid(ind + 1, matchsticks, sides, target))
                return true;

            // Undo / Backtrack
            sides[i] -= matchsticks[ind];
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

        int sum = 0;

        for (int stick : matchsticks)
            sum += stick;

        // Square requires 4 equal sides
        if (sum % 4 != 0)
            return false;

        int target = sum / 4;

        // Bigger sticks first -> better pruning
        sort(matchsticks.rbegin(), matchsticks.rend());

        // Impossible if biggest stick itself > side length
        if (matchsticks[0] > target)
            return false;

        vector<int> sides(4, 0);

        return isValid(0, matchsticks, sides, target);
    }
};