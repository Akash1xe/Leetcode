class Solution {
public:
    // Stores the number of people in the graph
    int n;

    vector<string> watchedVideosByFriends(
        vector<vector<string>>& watchedVideos,
        vector<vector<int>>& friends,
        int id,
        int level
    ) {
        n = friends.size();

        // visited[i] = true means person i has already been visited
        vector<bool> visited(n, false);

        // Queue is used for BFS traversal
        queue<int> q;

        // Start BFS from the given person
        q.push(id);
        visited[id] = true;

        // Keeps track of the current friendship level
        // level 0 = the given person
        // level 1 = direct friends
        // level 2 = friends of friends
        int current_level = 0;

        // BFS to reach the required friendship level
        while (!q.empty()) {

            // If we have reached the required level,
            // the queue contains exactly the people we need
            if (current_level == level)
                break;

            // Number of people present at the current level
            int size = q.size();

            // Process every person at the current level
            for (int i = 0; i < size; i++) {

                int curr = q.front();
                q.pop();

                // Visit all friends of the current person
                for (int friend_id : friends[curr]) {

                    // Only add a person once
                    if (!visited[friend_id]) {
                        visited[friend_id] = true;
                        q.push(friend_id);
                    }
                }
            }

            // Move to the next friendship level
            current_level++;
        }

        // freq[video] = number of friends at the required
        // level who have watched this video
        unordered_map<string, int> freq;

        // At this point, q contains only friends
        // exactly 'level' steps away from id
        while (!q.empty()) {

            int friend_id = q.front();
            q.pop();

            // Count every video watched by this friend
            for (string video : watchedVideos[friend_id]) {
                freq[video]++;
            }
        }

        // Convert unordered_map into a vector so that
        // we can sort the videos according to the problem's rules
        vector<pair<string, int>> video_freq_list(
            freq.begin(),
            freq.end()
        );

        // Sort using two conditions:
        // 1. Smaller frequency comes first
        // 2. If frequencies are equal, alphabetical order
        sort(
            video_freq_list.begin(),
            video_freq_list.end(),
            [](const pair<string, int>& a,
               const pair<string, int>& b) {

                // Same frequency -> alphabetical order
                if (a.second == b.second)
                    return a.first < b.first;

                // Different frequency -> smaller frequency first
                return a.second < b.second;
            }
        );

        // Store only the video names in the final answer
        vector<string> result;

        for (auto& p : video_freq_list) {
            result.push_back(p.first);
        }

        return result;
    }
};