class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = left + (right-left)/2;
//loop till there is space
        while (left<=right){
            //calculates mid
            mid = left+(right-left)/2;
            //returns if found
            if (nums[mid] == target){
                return mid;
            }
            //checks if left half is sorted and does target exists in it 
            if(nums[mid]>=nums[left]){
                if(nums[mid]>=target && target >= nums[left]){
                    right= mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            //hecks if right half is sorted and does target exists in it
            else{
                if(nums[mid]<=target && target <= nums[right]){
                    left= mid+1;
                }
                else{
                    right = mid-1;
                }    
            }
        
        
        
       
    }
    //if not found
        return -1;
    }
};