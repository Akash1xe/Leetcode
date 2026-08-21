class NumArray {
public:
    // tree[node] stores the sum of the segment represented by 'node'.
    //
    // Example:
    // nums = [1, 3, 5, 7]
    //
    //              tree[1] = 16
    //             /          \
    //       tree[2] = 4     tree[3] = 12
    //         /   \           /   \
    //        1     3         5     7
    //
    vector<int> tree;

    // Size of the original array
    int n;

    NumArray(vector<int>& nums) {

        n = nums.size();

        // A segment tree needs at most approximately 4*n
        // positions to safely store all nodes.
        tree.resize(4 * n);

        // Start building the segment tree.
        //
        // node = 1       -> root of segment tree
        // start = 0      -> first index of nums
        // end = n - 1    -> last index of nums
        build(1, 0, n - 1, nums);
    }


    // ---------------------------------------------------------
    // BUILD
    // ---------------------------------------------------------
    //
    // Builds the segment tree recursively.
    //
    // node  -> current tree node
    // start -> starting index of current segment
    // end   -> ending index of current segment
    //
    void build(int node, int start, int end, vector<int>& nums) {

        // If start == end, this segment contains only ONE element.
        // Therefore, we have reached a leaf node.
        if (start == end) {

            // Store the actual array value in this leaf.
            tree[node] = nums[start];

            return;
        }

        // Divide the current segment into two halves.
        int mid = (start + end) / 2;


        // Build the LEFT child.
        //
        // Left child of node = 2 * node
        //
        // It represents:
        // [start ... mid]
        build(2 * node, start, mid, nums);


        // Build the RIGHT child.
        //
        // Right child of node = 2 * node + 1
        //
        // It represents:
        // [mid + 1 ... end]
        build(2 * node + 1, mid + 1, end, nums);


        // Current node represents the whole segment [start...end].
        //
        // Its sum = sum of left child + sum of right child.
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }


    // ---------------------------------------------------------
    // UPDATE
    // ---------------------------------------------------------
    //
    // Changes nums[index] to val.
    //
    // Example:
    // nums = [1, 3, 5, 7]
    // update(2, 10)
    //
    // nums becomes:
    // [1, 3, 10, 7]
    //
    void update(int index, int val) {

        // Start from root and search for 'index'.
        updateTree(1, 0, n - 1, index, val);
    }


    // Helper function for update.
    //
    // We travel from root -> appropriate child -> leaf.
    //
    void updateTree(
        int node,
        int start,
        int end,
        int index,
        int val
    ) {

        // start == end means we reached the exact array index.
        if (start == end) {

            // Replace the old value with the new value.
            tree[node] = val;

            return;
        }


        // Find the middle of the current segment.
        int mid = (start + end) / 2;


        // If index is in the LEFT half,
        // move to the left child.
        if (index <= mid) {

            updateTree(
                2 * node,
                start,
                mid,
                index,
                val
            );
        }

        // Otherwise, index is in the RIGHT half.
        else {

            updateTree(
                2 * node + 1,
                mid + 1,
                end,
                index,
                val
            );
        }


        // The child has changed.
        //
        // Therefore, the current node's sum
        // must also be recalculated.
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }


    // ---------------------------------------------------------
    // RANGE SUM QUERY
    // ---------------------------------------------------------
    //
    // Returns sum of nums[left ... right].
    //
    // Example:
    // nums = [1, 3, 5, 7]
    //
    // sumRange(1, 3)
    //
    // Answer = 3 + 5 + 7 = 15
    //
    int sumRange(int left, int right) {

        // Start searching from the root.
        return query(1, 0, n - 1, left, right);
    }


    // Helper function for range sum query.
    //
    // node       -> current segment tree node
    // start/end  -> range represented by current node
    // left/right -> range requested by the user
    //
    int query(
        int node,
        int start,
        int end,
        int left,
        int right
    ) {

        // -----------------------------------------------------
        // CASE 1: COMPLETELY OUTSIDE
        // -----------------------------------------------------
        //
        // Current segment [start, end]
        // has NO overlap with [left, right].
        //
        // Therefore, this segment contributes nothing.
        //
        // Example:
        //
        // Current segment = [0, 2]
        // Query           = [4, 6]
        //
        // No overlap -> return 0.
        //
        if (end < left || right < start) {
            return 0;
        }


        // -----------------------------------------------------
        // CASE 2: COMPLETELY INSIDE
        // -----------------------------------------------------
        //
        // Current segment is completely contained
        // inside the requested range.
        //
        // Example:
        //
        // Current segment = [2, 4]
        // Query           = [1, 5]
        //
        // [2,4] is completely inside [1,5].
        //
        // We already know the sum of this entire segment,
        // so return it directly.
        //
        if (left <= start && end <= right) {
            return tree[node];
        }


        // -----------------------------------------------------
        // CASE 3: PARTIAL OVERLAP
        // -----------------------------------------------------
        //
        // The current segment partially overlaps
        // with the requested range.
        //
        // Therefore, we need to search both children.
        //
        int mid = (start + end) / 2;


        // Ask the LEFT child:
        // "How much of your segment belongs to the query?"
        int leftSum = query(
            2 * node,
            start,
            mid,
            left,
            right
        );


        // Ask the RIGHT child:
        // "How much of your segment belongs to the query?"
        int rightSum = query(
            2 * node + 1,
            mid + 1,
            end,
            left,
            right
        );


        // Combine the answers from both children.
        return leftSum + rightSum;
    }
};