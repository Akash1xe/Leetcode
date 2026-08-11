class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> st;

        for (int i = 0; i < asteroids.size(); i++) {

            // Positive asteroid moves to the right
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            }

            // Negative asteroid moves to the left
            else {

                // Destroy smaller positive asteroids
                while (!st.empty() &&
                       st.back() > 0 &&
                       st.back() < abs(asteroids[i])) {

                    st.pop_back();
                }

                // Both asteroids have the same size
                if (!st.empty() &&
                    st.back() == abs(asteroids[i])) {

                    st.pop_back();
                }

                // Negative asteroid survives
                else if (st.empty() || st.back() < 0) {

                    st.push_back(asteroids[i]);
                }
            }
        }

        return st;
    }
};