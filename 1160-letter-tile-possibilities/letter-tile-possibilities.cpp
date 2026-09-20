// Approach-2 (Using count of characters + backtracking)
// T.C : O(n!)
// S.C : O(n), total possible sequences = n! and each having n length
class Solution {
public:
    int total;
    void findSequences(vector<int>& count) {
        total++;

        for (int pos = 0; pos < 26; pos++) {
            if (count[pos] == 0) {
                continue;
            }

            count[pos]--;
            findSequences(count);
            count[pos]++;
        }
    }

    int numTilePossibilities(std::string tiles) {
        total = 0;

        vector<int> count(26, 0);
        for (char c : tiles) {
            count[c - 'A']++;
        }

        findSequences(count);
        return total - 1;
    }
};