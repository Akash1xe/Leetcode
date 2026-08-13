class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, -1);
        stack<int> st;

        // Traverse the array twice to handle circular nature.
        for (int i = 2 * n - 1; i >= 0; i--) {

            int index = i % n;

            // Remove elements that cannot be the next greater element.
            while (!st.empty() && st.top() <= nums[index]) {
                st.pop();
            }

            // Only fill answer during the first traversal.
            if (i < n && !st.empty()) {
                ans[index] = st.top();
            }

            // Store current element for future elements.
            st.push(nums[index]);
        }

        return ans;
    }
};