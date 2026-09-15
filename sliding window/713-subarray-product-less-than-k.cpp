class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        double product = 1;
        int ans = 0;
        int left = 0;

        if(k<=1)return 0;
        //for loops increase the window size from right
        for(int right = 0;right<nums.size();right++){
                //calculated product while expanding window 
                product *= nums[right];
                //when product exceeds k while loop starts shrinking from left
                while(product>=k){
                    product /= nums[left];
                    left++;
                }
            //calculates number of valid subarrays for each right and adds
            ans += right-left+1;
        }
        return ans;
        }

};