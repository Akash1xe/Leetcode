class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        int left = 0;
        int right = n-1;
        int maxLeft = 0;
        int maxRight = 0;
        int trapped=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxLeft){
                    maxLeft=height[left];
                }else{
                    trapped+=maxLeft-height[left];
                }

                left++;
            }else{
                   if(height[right]>=maxRight){
                    maxRight=height[right];
                }else{
                    trapped+=maxRight-height[right];
                }

                right--;
            }
        }

        return trapped;
    }
};