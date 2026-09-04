class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length()) return false;

        unordered_map<char, char> mapST; // s -> t
        unordered_map<char, char> mapTS; // t -> s

        for (int i = 0; i < s.length(); i++) {

            char c1 = s[i];
            char c2 = t[i];

            // Check mapping from s -> t
            if (mapST.find(c1) == mapST.end()) {
                mapST[c1] = c2;
            }
            else if (mapST[c1] != c2) {
                return false;
            }

            // Check mapping from t -> s
            if (mapTS.find(c2) == mapTS.end()) {
                mapTS[c2] = c1;
            }
            else if (mapTS[c2] != c1) {
                return false;
            }
        }

        return true;
    }
};