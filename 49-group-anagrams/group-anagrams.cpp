class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (string& str : strs) {

            vector<int> freq(26, 0);

            // Count frequency of each character
            for (char ch : str) {
                freq[ch - 'a']++;
            }

            // Convert frequency array into a unique key
            string key = "";

            for (int count : freq) {
                key += "#" + to_string(count);
            }

            mp[key].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto& it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};