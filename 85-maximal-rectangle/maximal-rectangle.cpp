class Solution {
public:

    // Function to find the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {

        // Stack stores indices of bars in increasing height order
        stack<int> st;

        // Stores the maximum rectangle area found so far
        int maxArea = 0;

        // Add a sentinel 0 at the end to process all remaining bars
        heights.push_back(0);

        // Traverse through every bar
        for (int i = 0; i < heights.size(); i++) {

            // If current bar is smaller, calculate areas
            // of bars that are taller than the current bar
            while (!st.empty() && heights[i] < heights[st.top()]) {

                // Get the height of the bar being removed
                int height = heights[st.top()];
                st.pop();

                // Calculate the width of the rectangle
                // If stack is empty, rectangle extends from 0 to i-1
                // Otherwise, it extends from st.top()+1 to i-1
                int width = st.empty() ? i : i - st.top() - 1;

                // Calculate area and update maximum area
                maxArea = max(maxArea, height * width);
            }

            // Store the current bar's index in the stack
            st.push(i);
        }

        // Remove the sentinel value to restore the original vector
        heights.pop_back();

        // Return the largest rectangle area
        return maxArea;
    }


    // Function to find the largest rectangle consisting only of 1s
    int maximalRectangle(vector<vector<char>>& matrix) {

        // If the matrix is empty, no rectangle exists
        if (matrix.empty()) return 0;

        // Number of columns in the matrix
        int m = matrix[0].size();

        // Height array represents a histogram for the current row
        vector<int> height(m, 0);

        // Stores the maximum rectangle area found
        int maxArea = 0;

        // Process the matrix row by row
        for (auto& row : matrix) {

            // Build the histogram for the current row
            for (int i = 0; i < m; i++) {

                // If the current cell is 1,
                // increase the height of the histogram
                if (row[i] == '1')
                    height[i]++;

                // If the current cell is 0,
                // the consecutive height becomes 0
                else
                    height[i] = 0;
            }

            // Find the largest rectangle in the current histogram
            maxArea = max(maxArea, largestRectangleArea(height));
        }

        // Return the maximum rectangle area in the entire matrix
        return maxArea;
    }
};