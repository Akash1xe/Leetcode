class Solution {
public:
    int answer = INT_MAX;

    void dfs(int node,
             vector<vector<pair<int,int>>>& adj,
             vector<bool>& visited)
    {
        visited[node] = true;

        for(auto &it : adj[node]) {

            int next = it.first;
            int wt   = it.second;

            // Update minimum edge seen so far
            answer = min(answer, wt);

            if(!visited[next])
                dfs(next, adj, visited);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &road : roads) {

            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<bool> visited(n + 1, false);

        dfs(1, adj, visited);

        return answer;
    }
};