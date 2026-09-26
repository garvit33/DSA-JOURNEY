class Solution {
public:
    //helper func calculates possible subarrays with sum<=goal
    int atmostsum(vector<int>& nums,int goal){
        if(goal<0) return 0;
        int left = 0;
        int ans = 0;
        int sum = 0;

        for(int right = 0;right<nums.size();right++){
        
            sum += nums[right];

            while(sum>goal){
                sum -= nums[left];
                left++;
            }

            ans+= right-left+1;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //to get subarrays exactly sum == goal then we do subarrays with sum <= goal - subarrays with sum<=goal-1 
        return atmostsum(nums,goal) - atmostsum(nums,goal-1);

    }
};