class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        // Store all deadends for O(1) lookup
        unordered_set<string> dead(deadends.begin(), deadends.end());

        // If starting point itself is blocked
        if (dead.count("0000"))
            return -1;

        queue<string> q;
        unordered_set<string> visited;

        // Start BFS from "0000"
        q.push("0000");
        visited.insert("0000");

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            // Process one BFS level
            while (size--) {

                string current = q.front();
                q.pop();

                // Target found
                if (current == target)
                    return moves;

                // Try rotating every wheel
                for (int i = 0; i < 4; i++) {

                    char original = current[i];

                    // Rotate wheel upward
                    current[i] = (original == '9') ? '0' : original + 1;

                    if (!dead.count(current) &&
                        !visited.count(current)) {

                        visited.insert(current);
                        q.push(current);
                    }

                    // Rotate wheel downward
                    current[i] = (original == '0') ? '9' : original - 1;

                    if (!dead.count(current) &&
                        !visited.count(current)) {

                        visited.insert(current);
                        q.push(current);
                    }

                    // Restore original digit
                    current[i] = original;
                }
            }

            // Next BFS level
            moves++;
        }

        return -1;
    }
};