class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();

        // Phase 1: merge robots that are already within `distance` at t = 0
        // (simultaneous merges), using ORIGINAL adjacency only.
        vector<long long> pos, spd;
        int start = 0;
        for (int i = 1; i < n; i++) {
            if ((long long)position[i] - position[i - 1] > distance) {
                pos.push_back(position[i - 1]);
                spd.push_back(speed[i - 1]);
                start = i;
            }
        }
        pos.push_back(position[n - 1]);
        spd.push_back(speed[n - 1]);

        // Phase 2: catch-up merges over time, right to left.
        int m = pos.size();
        long long topPos = pos[m - 1], topSpeed = spd[m - 1];
        int count = 1;

        for (int i = m - 2; i >= 0; i--) {
            if (spd[i] > topSpeed) {
                // will eventually catch up and merge
                continue;
            } else {
                topPos = pos[i];
                topSpeed = spd[i];
                count++;
            }
        }

        return count;
    }
};