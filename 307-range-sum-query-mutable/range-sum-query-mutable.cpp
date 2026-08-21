class NumArray {
public:
    vector<int> tree;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();

        // Segment tree needs approximately 4*n space
        tree.resize(4 * n);

        build(1, 0, n - 1, nums);
    }

    void build(int node, int start, int end, vector<int>& nums) {

        // Leaf node
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = (start + end) / 2;

        // Build left child
        build(2 * node, start, mid, nums);

        // Build right child
        build(2 * node + 1, mid + 1, end, nums);

        // Combine both children
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int index, int val) {
        updateTree(1, 0, n - 1, index, val);
    }

    void updateTree(int node, int start, int end, int index, int val) {

        // We reached the required index
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        // Index is in left half
        if (index <= mid) {
            updateTree(2 * node, start, mid, index, val);
        }
        // Index is in right half
        else {
            updateTree(2 * node + 1, mid + 1, end, index, val);
        }

        // Recalculate current node
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }

    int query(int node, int start, int end, int left, int right) {

        // Completely outside
        if (end < left || right < start) {
            return 0;
        }

        // Completely inside
        if (left <= start && end <= right) {
            return tree[node];
        }

        int mid = (start + end) / 2;

        int leftSum = query(
            2 * node,
            start,
            mid,
            left,
            right
        );

        int rightSum = query(
            2 * node + 1,
            mid + 1,
            end,
            left,
            right
        );

        return leftSum + rightSum;
    }
};