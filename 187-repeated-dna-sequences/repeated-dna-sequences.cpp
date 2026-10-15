class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mpp;
        vector<string> ans;

        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            if (right - left + 1 == 10) {
                string window = s.substr(left, 10);

                mpp[window]++;

                if (mpp[window] == 2) {
                    ans.push_back(window);
                }

                left++;
            }
        }

        return ans;
    }
};