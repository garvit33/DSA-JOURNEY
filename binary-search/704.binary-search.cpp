class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        //loop until there i no space to compare
        while(left<=right){
            //calculated mid
                mid = (right + left)/2;   
            //checks if target = mid 
            if (nums[mid] == target){
                return mid;
            }
            //shift left of mid
            if(nums[mid]>target){
                right = mid-1;
            }
            //shift right of mid
            else{
                left = mid+1;
            }
        }
        //if tgt not found
        return -1;
    }
};