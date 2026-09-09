class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        //take each element as a stationary element
        for(int i =0;i<nums.size()-2;i++){
            //checks duplicates and skips
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i+1;
            int right = nums.size()-1;
            //uses two pointer to find elements resulting 0 sum 
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];

                if(sum>0){
                    right--;
                }
                else if(sum<0){
                    left++;
                }
                else{
                    ans.push_back({
                        nums[i],
                        nums[left],
                        nums[right],
                    });
                    //handle suplicates after finding a valid pair
                    while(left<right && nums[left] == nums[left+1]){
                        left++;
                    }
                    while(left<right && nums[right] == nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }    

            }
        }
        return ans;

    }
};