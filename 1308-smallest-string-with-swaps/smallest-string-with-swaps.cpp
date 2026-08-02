class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find the ultimate parent of a node
    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    // Union by size
    void Union(int u, int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv])
            swap(pu, pv);

        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        int n = s.size();

        DSU dsu(n);

        // Connect all swappable indices
        for (auto &p : pairs)
            dsu.Union(p[0], p[1]);

        // Group indices by their ultimate parent
        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++)
            groups[dsu.findParent(i)].push_back(i);

        // Process every connected component
        for (auto &it : groups) {

            vector<int> indices = it.second;
            string chars = "";

            // Collect all characters
            for (int idx : indices)
                chars += s[idx];

            // Sort characters
            sort(chars.begin(), chars.end());

            // Indices are already in increasing order because
            // we traversed i from 0 to n-1.
            for (int i = 0; i < indices.size(); i++)
                s[indices[i]] = chars[i];
        }

        return s;
    }
};