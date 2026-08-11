class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (int asteroid : asteroids) {

            bool destroyed = false;

            // Collision is possible only when:
            // stack top -> right (+)
            // current   -> left (-)
            while (!st.empty() && st.top() > 0 && asteroid < 0) {

                if (st.top() < -asteroid) {
                    // Stack asteroid is smaller -> destroyed
                    st.pop();
                }
                else if (st.top() == -asteroid) {
                    // Both same size -> both destroyed
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    // Current asteroid is smaller -> destroyed
                    destroyed = true;
                    break;
                }
            }

            // Current asteroid survived all collisions
            if (!destroyed) {
                st.push(asteroid);
            }
        }

        // Stack contains answer in reverse order
        vector<int> ans(st.size());

        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};