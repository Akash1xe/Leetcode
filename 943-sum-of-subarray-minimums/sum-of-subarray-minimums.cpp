class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const long long MOD = 1e9 + 7;

        // ---------- Find Next Smaller Element (NSE) ----------
        vector<int> nse(n);
        stack<int> st1;

        for (int i = n - 1; i >= 0; i--) {

            // Remove elements >= arr[i]
            while (!st1.empty() && arr[st1.top()] >= arr[i]) {
                st1.pop();
            }

            // Next smaller element
            nse[i] = st1.empty() ? n : st1.top();

            st1.push(i);
        }

        // ---------- Find Previous Smaller or Equal (PSEE) ----------
        vector<int> psee(n);
        stack<int> st2;

        for (int i = 0; i < n; i++) {

            // Remove elements > arr[i]
            while (!st2.empty() && arr[st2.top()] > arr[i]) {
                st2.pop();
            }

            // Previous smaller or equal element
            psee[i] = st2.empty() ? -1 : st2.top();

            st2.push(i);
        }

        // ---------- Calculate Sum ----------
        long long sum = 0;

        for (int i = 0; i < n; i++) {

            // Number of choices on the left
            long long left = i - psee[i];

            // Number of choices on the right
            long long right = nse[i] - i;

            // Number of subarrays where arr[i] is minimum
            long long freq = left * right;

            // Contribution of arr[i]
            long long contribution =
                (freq * arr[i]) % MOD;

            sum = (sum + contribution) % MOD;
        }

        return sum;
    }
};