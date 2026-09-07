class Solution {
public:

    // This function checks:
    // If we remove the first 'k' indices from removable,
    // does p still remain a subsequence of s?
    bool canRemove(string& s, string& p, vector<int>& removable, int k) {

        // removed[i] = true means s[i] is considered deleted
        vector<bool> removed(s.size(), false);

        // Remove first k characters according to removable array
        for (int i = 0; i < k; i++) {
            removed[removable[i]] = true;
        }

        // j points to the current character of p
        int j = 0;

        // Traverse through s and try to match p as a subsequence
        for (int i = 0; i < s.size() && j < p.size(); i++) {

            // We can only use this character if it is NOT removed
            // and it matches the current character of p
            if (!removed[i] && s[i] == p[j]) {
                j++;
            }
        }

        // If j reaches p.size(),
        // then every character of p was matched
        return j == p.size();
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {

        // We are binary searching on the ANSWER:
        // number of characters we can remove

        // Minimum possible removals = 0
        int low = 0;

        // Maximum possible removals = removable.size()
        int high = removable.size();

        /*
            The condition is monotonic:

            k = 0   -> possible
            k = 1   -> possible
            k = 2   -> possible
            k = 3   -> possible
            k = 4   -> NOT possible
            k = 5   -> NOT possible

            Pattern:

            TRUE TRUE TRUE TRUE FALSE FALSE

            We need the LAST TRUE.

            So we binary search for the maximum k
            for which p is still a subsequence of s.
        */

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Check whether removing first 'mid' characters
            // still keeps p as a subsequence
            if (canRemove(s, p, removable, mid)) {

                // mid is a valid answer,
                // but there may be a larger valid answer
                // so search towards the right
                low = mid + 1;
            }
            else {

                // Removing mid characters breaks the subsequence,
                // so mid and every value greater than mid
                // cannot be our answer
                high = mid - 1;
            }
        }

        /*
            After binary search:

            high = last valid value (last TRUE)
            low  = first invalid value (first FALSE)

            Therefore return high.
        */

        return high;
    }
};