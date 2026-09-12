class Solution {
public:

    // Count how many pairs have product <= target.
    long long countProducts(vector<int>& nums1,
                            vector<int>& nums2,
                            long long target) {

        long long count = 0;
        int m = nums2.size();

        for (long long x : nums1) {

            // CASE 1: x > 0
            // x * nums2[j] increases as j increases.
            //
            // Pattern:
            // true true true false false
            //
            // Find first position where product > target.
            if (x > 0) {

                int low = 0;
                int high = m;

                while (low < high) {

                    int mid = low + (high - low) / 2;

                    if (x * nums2[mid] <= target) {
                        low = mid + 1;
                    }
                    else {
                        high = mid;
                    }
                }

                // nums2[0 ... low-1] are valid.
                count += low;
            }


            // CASE 2: x < 0
            // Multiplication by negative reverses the order.
            //
            // x * nums2[j] decreases as j increases.
            //
            // Pattern:
            // false false true true true
            //
            // Find first position where product <= target.
            else if (x < 0) {

                int low = 0;
                int high = m;

                while (low < high) {

                    int mid = low + (high - low) / 2;

                    if (x * nums2[mid] <= target) {
                        high = mid;
                    }
                    else {
                        low = mid + 1;
                    }
                }

                // nums2[low ... m-1] are valid.
                count += (m - low);
            }


            // CASE 3: x == 0
            //
            // Every product = 0.
            else {

                if (target >= 0) {
                    count += m;
                }
            }
        }

        return count;
    }


    long long kthSmallestProduct(vector<int>& nums1,
                                 vector<int>& nums2,
                                 long long k) {

        // Products can be as low as -1e10
        // and as high as +1e10.
        long long low = -10000000000LL;
        long long high = 10000000000LL;

        // Binary Search on the answer.
        while (low < high) {

            long long mid = low + (high - low) / 2;

            // How many products are <= mid?
            long long count = countProducts(nums1, nums2, mid);

            // If at least k products are <= mid,
            // kth product is mid or somewhere smaller.
            if (count >= k) {
                high = mid;
            }

            // Fewer than k products.
            // Need a larger product.
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};