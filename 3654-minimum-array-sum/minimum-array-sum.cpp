class Solution {
public:

    int n;

    // solve() returns the minimum possible sum
    // starting from index i with op1 and op2 operations left
    int solve(vector<int>& nums, int k, int i, int op1, int op2,
              vector<vector<vector<int>>>& dp) {

        // We have processed all elements
        if (i == n)
            return 0;

        // If this state is already calculated,
        // return the stored answer
        if (dp[i][op1][op2] != -1)
            return dp[i][op1][op2];

        // We want the minimum possible sum
        int result = INT_MAX;


        // --------------------------------------------------
        // CASE 1: Apply Operation 1 only
        // Operation 1 = ceil(nums[i] / 2)
        // --------------------------------------------------
        if (op1 > 0) {

            int newVal = (nums[i] + 1) / 2;

            // Current value after op1
            // Move to next index with one less op1
            int applyOp1 =
                newVal + solve(
                    nums, k, i + 1,
                    op1 - 1, op2, dp
                );

            result = min(result, applyOp1);
        }


        // --------------------------------------------------
        // CASE 2: Apply Operation 2 only
        // Operation 2 = nums[i] - k
        // It is possible only when nums[i] >= k
        // --------------------------------------------------
        if (op2 > 0 && nums[i] >= k) {

            int newVal = nums[i] - k;

            // Move to next index with one less op2
            int applyOp2 =
                newVal + solve(
                    nums, k, i + 1,
                    op1, op2 - 1, dp
                );

            result = min(result, applyOp2);
        }


        // --------------------------------------------------
        // CASE 3: Apply BOTH operations
        // We can apply:
        //     op1 -> op2
        // OR
        //     op2 -> op1
        // --------------------------------------------------
        if (op1 > 0 && op2 > 0) {


            // ==============================================
            // CASE 3A: Operation 1 -> Operation 2
            // ==============================================

            // First divide by 2
            int newVal = (nums[i] + 1) / 2;

            // Operation 2 can be applied only if
            // the value after operation 1 is >= k
            if (newVal >= k) {

                // Now subtract k
                newVal = newVal - k;

                int applyOp1Op2 =
                    newVal + solve(
                        nums, k, i + 1,
                        op1 - 1, op2 - 1, dp
                    );

                result = min(result, applyOp1Op2);
            }


            // ==============================================
            // CASE 3B: Operation 2 -> Operation 1
            // ==============================================

            // Operation 2 can be applied first only
            // when nums[i] >= k
            if (nums[i] >= k) {

                // First subtract k
                newVal = nums[i] - k;

                // Then apply operation 1
                newVal = (newVal + 1) / 2;

                int applyOp2Op1 =
                    newVal + solve(
                        nums, k, i + 1,
                        op1 - 1, op2 - 1, dp
                    );

                result = min(result, applyOp2Op1);
            }
        }


        // --------------------------------------------------
        // CASE 4: Don't apply any operation
        // Simply keep nums[i] as it is
        // --------------------------------------------------
        int noOperation =
            nums[i] + solve(
                nums, k, i + 1,
                op1, op2, dp
            );

        result = min(result, noOperation);


        // Store the answer for this state
        return dp[i][op1][op2] = result;
    }


    int minArraySum(vector<int>& nums, int k, int op1, int op2) {

        n = nums.size();

        // dp[i][op1][op2]
        //
        // i    = current index
        // op1  = number of Operation 1 still available
        // op2  = number of Operation 2 still available
        //
        // dp is created inside the main function
        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                op1 + 1,
                vector<int>(op2 + 1, -1)
            )
        );

        // Start from index 0 with all operations available
        return solve(nums, k, 0, op1, op2, dp);
    }
};