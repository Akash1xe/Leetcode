/*
MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=743cYtf3DJI
Company Tags                : Uber
Leetcode Link               : https://leetcode.com/problems/parallel-courses-iii/
*/

/****************************************************************************************** C++ ******************************************************************************************/

// Approach-1 (Using Simple Topological Sorting)
// T.C : O(V + E)
// S.C : O(V + E)
//
// Idea:
// 1. Convert the prerequisite list into a DAG (Directed Acyclic Graph).
// 2. Perform Kahn's Topological Sort.
// 3. While processing nodes in topological order, compute the earliest
//    finishing time for every course.
// 4. Since a course may have multiple prerequisites, its completion time
//    depends on the prerequisite that finishes the latest.

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        // Adjacency list
        // u -> v means u must be completed before v
        unordered_map<int, vector<int>> adj;

        // indegree[i] = number of prerequisites remaining for course i
        vector<int> indegree(n, 0);

        // Build the graph
        for(auto &vec : relations) {

            // Convert 1-based indexing to 0-based indexing
            int u = vec[0] - 1;
            int v = vec[1] - 1;

            adj[u].push_back(v);
            indegree[v]++;
        }

        // Queue for Kahn's Algorithm
        queue<int> que;

        // maxTime[i] = earliest time by which course i can be completed
        vector<int> maxTime(n, 0);

        // Courses having no prerequisites can start immediately
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                que.push(i);

                // Completion time = its own duration
                maxTime[i] = time[i];
            }
        }

        // Standard Topological BFS
        while(!que.empty()) {

            int u = que.front();
            que.pop();

            // Visit all courses dependent on u
            for(int &v : adj[u]) {

                // Course v can start only after ALL its prerequisites finish.
                // Therefore, keep the maximum finishing time among all parents.
                //
                // Example:
                // Parent1 finishes at 5
                // Parent2 finishes at 8
                // time[v] = 3
                //
                // Finish time of v = max(5+3, 8+3) = 11
                maxTime[v] = max(maxTime[v], maxTime[u] + time[v]);

                // One prerequisite has now been processed
                indegree[v]--;

                // If all prerequisites are completed,
                // push this course into the queue
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        // Overall answer = maximum finishing time among all courses
        return *max_element(begin(maxTime), end(maxTime));
    }
};