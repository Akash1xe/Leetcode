class Solution {
public:
    int minSteps(string s, string t) {

        // Frequency arrays
        vector<int> freqS(26, 0);
        vector<int> freqT(26, 0);

        // Count characters in s
        for (char ch : s)
            freqS[ch - 'a']++;

        // Count characters in t
        for (char ch : t)
            freqT[ch - 'a']++;

        int steps = 0;

        // Count how many characters are missing in t
        for (int i = 0; i < 26; i++) {

            if (freqS[i] > freqT[i]) {
                steps += (freqS[i] - freqT[i]);
            }
        }

        return steps;
    }
};