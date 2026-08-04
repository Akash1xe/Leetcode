class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        // indegree[i]  = Number of people who trust person i
        // outdegree[i] = Number of people person i trusts
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        // Build the indegree and outdegree arrays
        for (auto &edge : trust) {
            int u = edge[0]; // Person who trusts
            int v = edge[1]; // Person being trusted

            outdegree[u]++; // u trusts someone
            indegree[v]++;  // v receives one more trust
        }

        // The town judge must satisfy:
        // 1. Trusts nobody        -> outdegree = 0
        // 2. Trusted by everyone  -> indegree = n - 1
        for (int person = 1; person <= n; person++) {

            if (indegree[person] == n - 1 && outdegree[person] == 0)
                return person;
        }

        // No judge exists
        return -1;
    }
};

/*
Time Complexity: O(n + m)
- m = trust.size()
- Building the indegree and outdegree arrays takes O(m).
- Checking all n people takes O(n).

Space Complexity: O(n)
- Two extra arrays (indegree and outdegree) of size (n + 1).
*/