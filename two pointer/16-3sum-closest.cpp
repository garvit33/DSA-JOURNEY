class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        //tracks closest sum
        int closest = nums[0]+nums[1]+nums[2];

        //first variable which is fixed
        for(int i = 0;i<nums.size()-2;i++){

            //for every fixed element there moves a two pointer
            int left = i+1;
            int right = nums.size()-1;

            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];

                //caclultaes which sum is closest
                if(abs(sum-target) < abs(closest-target)){
                    closest = sum;
                }


                if(sum == target){
                    return sum;
                }

                else if(sum>target){
                    right--;
                }

                else{
                    left++;
                }
            }
        }
        return closest;
    }    
};