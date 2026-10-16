class Solution {
public:

    int findDays(vector<int>& weights, int cap) {
        int load = 0;
        int day = 1;

        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > cap) {
                day++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }

        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int numberOfDaysRequired = findDays(weights, mid);

            if (numberOfDaysRequired <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};