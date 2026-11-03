class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;

        unordered_map<char, int> count;

        // Count characters in s
        for(char ch : s) {
            count[ch]++;
        }

        // Subtract characters using t
        for(char ch : t) {

            if(count[ch] == 0) {
                return false;
            }

            count[ch]--;
        }

        return true;
    }
};