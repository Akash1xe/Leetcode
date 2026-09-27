class Solution {
public:

    int count = 0;
    string ans = "";

    void solve(int n, int k, string& curr, vector<int>& used) {

        // One complete permutation is formed
        if (curr.size() == n) {

            count++;

            // We reached the k-th permutation
            if (count == k) {
                ans = curr;
            }

            return;
        }

        // Try numbers from 1 to n
        // This keeps permutations in lexicographical order
        for (int i = 1; i <= n; i++) {

            // Already used
            if (used[i]) {
                continue;
            }

            // Choose
            used[i] = 1;
            curr += to_string(i);

            // Explore
            solve(n, k, curr, used);

            // If answer is already found,
            // no need to generate more permutations
            if (!ans.empty()) {
                return;
            }

            // Backtrack
            curr.pop_back();
            used[i] = 0;
        }
    }

    string getPermutation(int n, int k) {

        vector<int> used(n + 1, 0);

        string curr = "";

        solve(n, k, curr, used);

        return ans;
    }
};