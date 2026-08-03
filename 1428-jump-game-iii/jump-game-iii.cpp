class Solution {
public:
    bool dfs(vector<int>& arr, int index, vector<bool>& visited) {

        // Out of bounds
        if (index < 0 || index >= arr.size())
            return false;

        // Already visited
        if (visited[index])
            return false;

        // Found an index with value 0
        if (arr[index] == 0)
            return true;

        // Mark current index as visited
        visited[index] = true;

        // Jump forward
        bool forward = dfs(arr, index + arr[index], visited);

        // Jump backward
        bool backward = dfs(arr, index - arr[index], visited);

        return forward || backward;
    }

    bool canReach(vector<int>& arr, int start) {

        vector<bool> visited(arr.size(), false);

        return dfs(arr, start, visited);
    }
};