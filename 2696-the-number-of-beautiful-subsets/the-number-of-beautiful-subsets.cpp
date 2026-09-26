class Solution {
public:

    int func(int ind, vector<int>& nums, int k, vector<int>& temp) {

        
        if (ind == nums.size()) {
            return 1;
        }

     
        int skip = func(ind + 1, nums, k, temp);


       
        int take = 0;

        bool canTake = true;

       
        for (int i = 0; i < temp.size(); i++) {

            if (abs(temp[i] - nums[ind]) == k) {
                canTake = false;
                break;
            }
        }

        if (canTake) {

           
            temp.push_back(nums[ind]);

            take = func(ind + 1, nums, k, temp);

           
            temp.pop_back();
        }

        return take + skip;
    }


    int beautifulSubsets(vector<int>& nums, int k) {

        vector<int> temp;

        // -1 because empty subset is also counted
        return func(0, nums, k, temp) - 1;
    }
};