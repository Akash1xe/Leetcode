class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> st; 
        // stack will store indices of bars (not heights)
        // it helps us find Previous Smaller Element (PSE)

        int max_area = 0; 
        // stores the maximum rectangle area found so far

        for(int i = 0; i < heights.size(); i++) {
            // iterate through all bars in histogram

            while(!st.empty() && heights[st.top()] > heights[i]) {
                // if current bar is smaller than stack top
                // it means we found the Next Smaller Element (NSE)

                int element = st.top(); 
                // index of the bar for which we are calculating area

                st.pop(); 
                // remove it because we found its NSE

                int nse = i; 
                // Next Smaller Element index is current index i

                int pse = st.empty() ? -1 : st.top(); 
                // Previous Smaller Element index
                // if stack empty → no smaller on left → -1

                // width = (nse - pse - 1)
                // area = height * width
                max_area = max(max_area, heights[element] * (nse - pse - 1));
            }

            st.push(i); 
            // push current index into stack
        }

        // process remaining elements in stack
        while(!st.empty()) {
            int element = st.top(); 
            // index of remaining bar

            st.pop(); 
            // remove it

            int nse = heights.size();  
            // no smaller element to right → assume NSE = n (end)

            int pse = st.empty() ? -1 : st.top(); 
            // find previous smaller element

            max_area = max(max_area, heights[element] * (nse - pse - 1));
            // compute area again
        }

        return max_area; 
        // return final maximum rectangle area
    }
};

/*
⏱️ Time Complexity
O(n)

💾 Space Complexity
O(n)

*/