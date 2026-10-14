class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int left = 0;
        int right = 0;

        int sum = 0;

        int n = arr.size() - 1;

        int count = 0;

        while (right <= n) {

            sum += arr[right];

            if (right - left + 1 > k) {
                sum -= arr[left];
                left++;
            }

            int average = sum / k;

            if (right - left + 1 == k && average >= threshold) {

                count++;
            }

            right ++ ;
        }

        return count;
    }
};