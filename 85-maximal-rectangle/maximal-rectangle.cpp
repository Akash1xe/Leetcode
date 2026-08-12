class Solution {
public:

    // Function to find the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        // stack stores indices of bars
        // it helps us find Previous Smaller Element (PSE)


        int max_area = 0;
        // stores the maximum rectangle area found so far


        for (int i = 0; i < heights.size(); i++) {
            // iterate through all bars in histogram


            while (!st.empty() && heights[st.top()] > heights[i]) {
                // current bar is smaller than stack top
                // so we found the Next Smaller Element (NSE)


                int element = st.top();
                // index of the bar for which we calculate area


                st.pop();
                // remove it because its NSE is found


                int nse = i;
                // current index is the Next Smaller Element


                int pse = st.empty() ? -1 : st.top();
                // Previous Smaller Element
                // if stack is empty → no smaller element on left → -1


                // width = nse - pse - 1
                // area = height * width
                max_area = max(max_area,
                               heights[element] * (nse - pse - 1));
            }


            st.push(i);
            // push current index into stack
        }


        // Process all remaining bars
        // They don't have a smaller element on the right
        while (!st.empty()) {

            int element = st.top();
            // index of remaining bar

            st.pop();
            // remove it


            int nse = heights.size();
            // no smaller element on right
            // so NSE = size of histogram


            int pse = st.empty() ? -1 : st.top();
            // Previous Smaller Element


            max_area = max(max_area,
                           heights[element] * (nse - pse - 1));
            // calculate area
        }


        return max_area;
        // return maximum rectangle area
    }


    // Function to find the maximum rectangle of 1s
    // in the binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {

        // If matrix is empty, answer is 0
        if (matrix.empty()) return 0;


        int m = matrix[0].size();
        // number of columns


        vector<int> heights(m, 0);
        // heights[i] stores the number of consecutive 1s
        // ending at the current row


        int max_area = 0;
        // stores the maximum rectangle area


        // Traverse the matrix row by row
        for (auto& row : matrix) {

            // Update histogram heights
            for (int i = 0; i < m; i++) {

                if (row[i] == '1') {
                    // if current cell is 1,
                    // increase the consecutive height

                    heights[i]++;
                }
                else {
                    // if current cell is 0,
                    // consecutive height becomes 0

                    heights[i] = 0;
                }
            }


            // Treat the current row as a histogram
            // and find the largest rectangle
            max_area = max(max_area,
                           largestRectangleArea(heights));
        }


        return max_area;
        // return maximum rectangle area in the matrix
    }
};


/*
⏱️ Time Complexity

For each row:
    O(m) → build the histogram
    O(m) → largestRectangleArea()

For n rows:

O(n * m)


💾 Space Complexity

O(m) → heights array
O(m) → stack

Overall:

O(m)
*/