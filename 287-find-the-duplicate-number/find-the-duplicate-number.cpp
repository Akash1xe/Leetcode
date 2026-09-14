class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Phase 1: Find intersection point inside the cycle
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];          // Move 1 step
            fast = nums[nums[fast]];    // Move 2 steps
        } while (slow != fast);

        // Phase 2: Find the entrance of the cycle
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};