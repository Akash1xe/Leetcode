class CustomStack {
private:
    int maxSize;
    vector<int> st;
    vector<int> inc;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        inc.resize(maxSize, 0);
    }

    void push(int x) {
        if (st.size() == maxSize) {
            return;
        }

        st.push_back(x);
    }

    int pop() {
        if (st.empty()) {
            return -1;
        }

        int index = st.size() - 1;

        // Add pending increment to the current element
        int ans = st[index] + inc[index];

        // Pass the increment to the element below
        if (index > 0) {
            inc[index - 1] += inc[index];
        }

        // Clear the increment before removing the element
        inc[index] = 0;

        st.pop_back();

        return ans;
    }

    void increment(int k, int val) {
        if (st.empty()) {
            return;
        }

        // Store the increment at the boundary of bottom k elements
        int index = min(k, (int)st.size()) - 1;

        inc[index] += val;
    }
};