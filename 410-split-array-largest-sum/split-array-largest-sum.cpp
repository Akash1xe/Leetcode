class Solution {
public:

    // This function calculates how many students are needed
    // if each student can read at most 'pages' number of pages
    int countStudent(vector<int>& nums, int pages) {
        
        int student = 1; // start with 1 student
        long long pagesStudent = 0; // pages assigned to current student

        // loop through all books
        for (int i = 0; i < nums.size(); i++) {

            // if current book can be added without exceeding limit
            if (pagesStudent + nums[i] <= pages) {
                pagesStudent += nums[i]; // add book to current student
            } 
            else {
                // need a new student
                student += 1;

                // assign current book to new student
                pagesStudent = nums[i];
            }
        }

        // return total students required
        return student;
    }

    // This function finds the minimum possible maximum pages
    int findPages(vector<int>& nums, int size, int k) {

        // if students are more than books, not possible
        if (k > size) return -1;

        // minimum pages = maximum single book (because one book must be assigned)
        int low = *max_element(nums.begin(), nums.end());

        // maximum pages = sum of all books (one student reads all)
        int high = accumulate(nums.begin(), nums.end(), 0);

        // binary search on answer
        while (low <= high) {

            // find mid value (candidate for max pages)
            int mid = low + (high - low) / 2;

            // check how many students are needed if max pages = mid
            int student = countStudent(nums, mid);

            // if more students needed than allowed
            if (student > k) {
                // increase pages limit
                low = mid + 1;
            } 
            else {
                // try to minimize further
                high = mid - 1;
            }
        }

        // final answer is stored in low
        return low;
    }

    // main function called by user
    int splitArray(vector<int>& nums, int k) {

        // call helper function
        return findPages(nums, nums.size(), k);
    }
};