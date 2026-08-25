class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> arr(26, 0);

        int m = s.length();
        int n = p.length();

        // Store frequency of characters in p
        for (char ch : p) {
            arr[ch - 'a']++;
        }

        int i = 0, j = 0;
        vector<int> result;

        // Sliding window
        while (j < m) {

            // Add s[j] to the window
            arr[s[j] - 'a']--;

            // Window size becomes equal to p
            if (j - i + 1 == n) {

                // All frequencies are zero => window is an anagram
                if (all_of(arr.begin(), arr.end(),
                           [](int x) { return x == 0; })) {
                    result.push_back(i);
                }

                // Remove s[i] from the window
                arr[s[i] - 'a']++;
                i++;
            }

            j++;
        }

        return result;
    }
};