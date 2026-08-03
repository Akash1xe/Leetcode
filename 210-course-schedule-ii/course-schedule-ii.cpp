class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // Adjacency list representing the graph
        // prerequisite --> course
        vector<vector<int>> adj(numCourses);

        // Stores the number of prerequisites for each course
        vector<int> inDegree(numCourses, 0);

        // Build the graph and calculate in-degree
        for (auto &pre : prerequisites) {

            int course = pre[0];
            int prerequisite = pre[1];

            // Edge : prerequisite -> course
            adj[prerequisite].push_back(course);

            // One more prerequisite needed for this course
            inDegree[course]++;
        }

        // Queue for all courses having no prerequisites
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        // Stores the valid order of taking courses
        vector<int> order;

        // Perform Kahn's Algorithm (Topological Sort)
        while (!q.empty()) {

            // Take a course whose prerequisites are already completed
            int node = q.front();
            q.pop();

            order.push_back(node);

            // Remove this course from the graph
            for (int neighbor : adj[node]) {

                // One prerequisite is completed
                inDegree[neighbor]--;

                // If all prerequisites are completed,
                // this course is ready to be taken
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If every course is processed,
        // a valid ordering exists
        if (order.size() == numCourses)
            return order;

        // Cycle exists, so it is impossible
        // to finish all courses
        return {};
    }
};

/*
Time Complexity : O(V + E)
    V = Number of courses
    E = Number of prerequisite pairs

    - Building the graph takes O(E).
    - Calculating in-degree takes O(E).
    - Every course is pushed and popped from the queue once => O(V).
    - Every edge is processed exactly once => O(E).

    Total = O(V + E)

Space Complexity : O(V + E)

    - Adjacency list = O(V + E)
    - In-degree array = O(V)
    - Queue = O(V)
    - Answer vector = O(V)

    Total = O(V + E)


Intuition:

Think of every course as a node in a graph.

If course B must be completed before course A,
draw an edge:
        B ----> A

The in-degree of a node represents how many prerequisites
are still required before taking that course.

1. First, compute the in-degree of every course.
2. Any course with in-degree = 0 has no remaining prerequisites,
   so it can be taken immediately.
3. Process these courses using a queue.
4. After taking a course, remove its outgoing edges by
   decreasing the in-degree of its neighboring courses.
5. Whenever a neighbor's in-degree becomes 0,
   it is now ready to be taken, so push it into the queue.
6. Continue until the queue becomes empty.

If we successfully process all courses,
a valid topological ordering exists.

If some courses are never processed,
they are part of a cycle, making it impossible
to complete all courses.
*/