class Solution {
public:

    class DSU {
    public:
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int node) {
            if (parent[node] == node)
                return node;

            return parent[node] = find(parent[node]);
        }

        bool unite(int u, int v) {
            u = find(u);
            v = find(v);

            if (u == v)
                return false;

            if (size[u] < size[v])
                swap(u, v);

            parent[v] = u;
            size[u] += size[v];

            return true;
        }
    };

    int kruskal(int n, vector<vector<int>>& edges, int skip, int force) {

        DSU ds(n);

        int cost = 0;
        int count = 0;

        // Force an edge to be included
        if (force != -1) {
            for (auto& e : edges) {
                if (e[3] == force) {
                    ds.unite(e[0], e[1]);
                    cost += e[2];
                    count++;
                    break;
                }
            }
        }

        // Apply Kruskal
        for (auto& e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];
            int index = e[3];

            if (index == skip || index == force)
                continue;

            if (ds.unite(u, v)) {
                cost += w;
                count++;
            }
        }

        if (count != n - 1)
            return INT_MAX;

        return cost;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n, vector<vector<int>>& edges) {

        int m = edges.size();

        // Store original index
        vector<vector<int>> sortedEdges;

        for (int i = 0; i < m; i++) {
            sortedEdges.push_back({
                edges[i][0],
                edges[i][1],
                edges[i][2],
                i
            });
        }

        // Sort by weight
        sort(sortedEdges.begin(), sortedEdges.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });

        // Original MST cost
        int mstCost = kruskal(n, sortedEdges, -1, -1);

        vector<int> critical;
        vector<int> pseudo;

        for (int i = 0; i < m; i++) {

            // Check whether removing edge increases MST cost
            int withoutEdge = kruskal(n, sortedEdges, i, -1);

            if (withoutEdge > mstCost) {
                critical.push_back(i);
            }

            // Check whether forcing edge gives same MST cost
            else {
                int withEdge = kruskal(n, sortedEdges, -1, i);

                if (withEdge == mstCost) {
                    pseudo.push_back(i);
                }
            }
        }

        return {critical, pseudo};
    }
};