class Solution {
public:

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());

        vector<vector<string>> ans;

        // If endWord is not present, no transformation is possible
        if (st.find(endWord) == st.end())
            return ans;

        // parent[word] = all words from which we can reach 'word'
        // while staying on a shortest path
        unordered_map<string, vector<string>> parent;

        queue<string> q;
        q.push(beginWord);

        // Remove beginWord if it exists
        st.erase(beginWord);

        bool found = false;

        while (!q.empty() && !found) {

            int sz = q.size();

            // Words discovered in this BFS level
            unordered_set<string> usedThisLevel;

            while (sz--) {

                string word = q.front();
                q.pop();

                for (int i = 0; i < word.size(); i++) {

                    string temp = word;

                    // Try changing current character
                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        if (ch == word[i])
                            continue;

                        temp[i] = ch;

                        // We found a valid next word
                        if (st.find(temp) != st.end()) {

                            // Store parent
                            parent[temp].push_back(word);

                            // First time discovering this word
                            if (usedThisLevel.find(temp) == usedThisLevel.end()) {
                                usedThisLevel.insert(temp);
                                q.push(temp);
                            }

                            // End word reached
                            if (temp == endWord) {
                                found = true;
                            }
                        }
                    }
                }
            }

            // Remove words only after completing the level.
            // This is important because another word in the
            // same level may also reach the same next word.
            for (auto &word : usedThisLevel) {
                st.erase(word);
            }
        }

        // If endWord was never reached
        if (!found)
            return ans;

        // Backtracking from endWord -> beginWord
        vector<string> path;
        path.push_back(endWord);

        function<void(string)> dfs = [&](string word) {

            // We reached beginWord
            if (word == beginWord) {

                vector<string> temp = path;

                reverse(temp.begin(), temp.end());

                ans.push_back(temp);

                return;
            }

            // Try every possible parent
            for (string p : parent[word]) {

                path.push_back(p);

                dfs(p);

                path.pop_back();
            }
        };

        dfs(endWord);

        return ans;
    }
};

/*
INTUITION:

Word Ladder II asks for ALL shortest paths.

We use BFS because BFS explores the graph level by level.
Therefore, the first time we reach endWord, we know that
the transformation length is minimum.

But we cannot simply mark a word visited immediately.

Example:

        hit
       /   \
     hot   hig
       \   /
        hog

Both "hot" and "hig" may reach "hog" in the same BFS level.

Therefore, we allow multiple parents for a word:

parent["hog"] = {"hot", "hig"}

This is why we remove words from the set only AFTER
finishing the current BFS level.

After BFS, we have a structure like:

parent[hot] = {hit}
parent[dot] = {hot}
parent[dog] = {dot}
parent[cog] = {dog, log}

Then we start from endWord and backtrack through all
its parents.

BFS:
    Finds the shortest distance
    + records all possible shortest parents

DFS:
    Reconstructs all shortest paths

Time Complexity:
    Approximately O(N * L * 26) for BFS
    plus the cost of generating all answer paths.

N = number of words
L = length of each word
*/ 