class Solution {
public:
    vector<int> parent, sz;

    // Find the ultimate parent of a node
    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]); // Path Compression
    }

    // Union by Size
    void Union(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (sz[u] < sz[v]) {
            parent[u] = v;
            sz[v] += sz[u];
        } else {
            parent[v] = u;
            sz[u] += sz[v];
        }
    }

    bool equationsPossible(vector<string>& equations) {

        // Initialize DSU
        parent.resize(26);
        sz.assign(26, 1);

        for (int i = 0; i < 26; i++)
            parent[i] = i;

        // Pass 1: Merge all equal variables
        for (string eq : equations) {

            if (eq[1] == '=') {

                int u = eq[0] - 'a';
                int v = eq[3] - 'a';

                Union(u, v);
            }
        }

        // Pass 2: Check all inequalities
        for (string eq : equations) {

            if (eq[1] == '!') {

                int u = eq[0] - 'a';
                int v = eq[3] - 'a';

                // If both belong to same component,
                // inequality cannot be satisfied
                if (find(u) == find(v))
                    return false;
            }
        }

        return true;
    }
};