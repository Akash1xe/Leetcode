class Solution {
public:

    int solve(int ind,
              vector<string>& words,
              vector<int>& freq,
              vector<int>& score) {

        // No more words left
        if (ind == words.size()) {
            return 0;
        }

        // -------------------------
        // Choice 1: Do not pick
        // -------------------------
        int notPick = solve(ind + 1, words, freq, score);

        // -------------------------
        // Choice 2: Pick
        // -------------------------

        int wordScore = 0;
        bool canPick = true;

        // Try using letters of current word
        for (char ch : words[ind]) {

            freq[ch - 'a']--;

            wordScore += score[ch - 'a'];

            // Not enough of this character
            if (freq[ch - 'a'] < 0) {
                canPick = false;
            }
        }

        int pick = 0;

        if (canPick) {
            pick = wordScore +
                   solve(ind + 1, words, freq, score);
        }

        // -------------------------
        // BACKTRACK
        // Restore all letters
        // -------------------------
        for (char ch : words[ind]) {
            freq[ch - 'a']++;
        }

        return max(pick, notPick);
    }

    int maxScoreWords(vector<string>& words,
                      vector<char>& letters,
                      vector<int>& score) {

        vector<int> freq(26, 0);

        // Count available letters
        for (char ch : letters) {
            freq[ch - 'a']++;
        }

        return solve(0, words, freq, score);
    }
};