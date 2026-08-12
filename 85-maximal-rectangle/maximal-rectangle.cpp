class Solution {
public:

    // ---------------------------------------------------------
    // Function: Find the largest rectangle area in a histogram
    // Example: [2, 1, 5, 6, 2, 3]
    // ---------------------------------------------------------
    int largestRectangleArea(vector<int>& heights) {

        // Stack stores INDEXES of histogram bars.
        // The indexes in stack maintain increasing heights.
        stack<int> st;

        // Stores the maximum rectangle area found so far.
        int maxArea = 0;

        // Number of bars in histogram.
        int n = heights.size();


        // We go one extra step: i == n
        // This extra position acts like a bar of height 0.
        //
        // Why?
        // It forces all remaining bars in the stack to be popped
        // and their rectangle areas to be calculated.
        for (int i = 0; i <= n; i++) {

            // Normally:
            //     currHeight = heights[i]
            //
            // But when i == n, there is no heights[n].
            // So we pretend there is a height 0.
            int currHeight = (i == n) ? 0 : heights[i];


            // If current height is smaller than the height
            // at the stack's top index, the rectangle belonging
            // to that taller bar can no longer continue.
            //
            // Therefore, we calculate its rectangle area.
            while (!st.empty() && currHeight < heights[st.top()]) {

                // Height of the rectangle.
                int h = heights[st.top()];

                // Remove this bar from the stack.
                st.pop();


                // Calculate the width of the rectangle.
                int width;

                // If stack is empty:
                //
                // There is NO smaller bar on the left.
                // Therefore, rectangle can extend from index 0
                // all the way to i - 1.
                //
                // Number of bars = i
                if (st.empty())
                    width = i;

                else {

                    // st.top() is the index of the first smaller
                    // bar on the LEFT.
                    //
                    // i is the first smaller bar on the RIGHT.
                    //
                    // So the rectangle exists between them:
                    //
                    //        left smaller
                    //             |
                    //             v
                    //     [ rectangle ]
                    //             ^
                    //             |
                    //        right smaller
                    //
                    // Therefore:
                    // width = right - left - 1
                    width = i - st.top() - 1;
                }


                // Rectangle Area = Height × Width
                maxArea = max(maxArea, h * width);
            }


            // Put current index into the stack.
            //
            // Stack maintains indexes whose heights are
            // in increasing order.
            st.push(i);
        }


        // Return the largest rectangle found.
        return maxArea;
    }


    // ---------------------------------------------------------
    // Function: Find largest rectangle consisting only of 1s
    // in a binary matrix.
    // ---------------------------------------------------------
    int maximalRectangle(vector<vector<char>>& matrix) {

        // If matrix is empty, there is no rectangle.
        if (matrix.empty()) return 0;


        // Number of rows.
        int rows = matrix.size();

        // Number of columns.
        int cols = matrix[0].size();


        // heights[j] tells us:
        //
        // "How many consecutive 1s are there vertically
        // ending at the current row?"
        //
        // Initially everything is 0.
        vector<int> heights(cols, 0);


        // Stores the maximum rectangle area.
        int maxArea = 0;


        // Process matrix row by row.
        for (int i = 0; i < rows; i++) {


            // -------------------------------------------------
            // STEP 1:
            // Convert current row into a histogram.
            // -------------------------------------------------
            for (int j = 0; j < cols; j++) {

                // If current cell is 1:
                //
                // Extend the previous vertical column height.
                if (matrix[i][j] == '1')
                    heights[j] += 1;

                else {

                    // If current cell is 0:
                    //
                    // A rectangle cannot pass through 0.
                    // So the height becomes 0.
                    heights[j] = 0;
                }
            }


            // -------------------------------------------------
            // STEP 2:
            // Find the largest rectangle in this histogram.
            // -------------------------------------------------
            //
            // We reuse the LC 84 function.
            maxArea = max(maxArea, largestRectangleArea(heights));
        }


        // Return the largest rectangle of 1s.
        return maxArea;
    }
};