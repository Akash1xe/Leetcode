class DSU {
public:
    vector<int> parent, size;

    // Constructor
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        // Initially every node is its own parent
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find the ultimate parent of a node
    // Path compression makes future searches faster
    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    // Union two components using size
    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        // Already in the same component
        if (pu == pv)
            return;

        // Attach the smaller component to the larger one
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        // Create DSU for all account indices
        DSU dsu(n);

        // Stores:
        // email -> first account index where this email appeared
        unordered_map<string, int> emailOwner;

        // ---------------- Step 1 ----------------
        // Merge accounts that share at least one email
        for (int i = 0; i < n; i++) {

            // Skip index 0 because it is the person's name
            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                // First time seeing this email
                if (emailOwner.find(email) == emailOwner.end()) {

                    // Remember which account owns it
                    emailOwner[email] = i;
                }
                else {

                    // Email already exists
                    // Merge current account with previous account
                    dsu.unite(i, emailOwner[email]);
                }
            }
        }

        // ---------------- Step 2 ----------------
        // Group all emails according to the DSU root
        unordered_map<int, vector<string>> mergedEmails;

        // Traverse every unique email
        for (auto &entry : emailOwner) {

            string email = entry.first;
            int accountIndex = entry.second;

            // Find the ultimate parent of this account
            int root = dsu.find(accountIndex);

            // Store this email under its root component
            mergedEmails[root].push_back(email);
        }

        // ---------------- Step 3 ----------------
        // Build the final answer
        vector<vector<string>> ans;

        // Each root represents one merged account
        for (auto &entry : mergedEmails) {

            int root = entry.first;

            // Get all emails belonging to this component
            vector<string> &emails = entry.second;

            // Emails must be returned in sorted order
            sort(emails.begin(), emails.end());

            vector<string> account;

            // First element is the person's name
            account.push_back(accounts[root][0]);

            // Add all sorted emails
            for (string &email : emails)
                account.push_back(email);

            // Add merged account to answer
            ans.push_back(account);
        }

        return ans;
    }
};