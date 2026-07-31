class Solution {
public:
//helper function to check valid splits without exceeding the sum
    int cansplit(vector<int>& nums, int k,int p){
        int count = 0;
        int splits = 1;
        //iterates the array
        for (int i =0;i<nums.size();i++){
            //if window exceeds the sum splits
            if(count+nums[i] > p){
                splits++;
                count = nums[i];
            }
            //keeps adding the elements
            else{
                count+=nums[i];
            }
        }
        //return valid or not
        return splits<=k;

    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(),nums.end());
        int right = 0;
        //calculates sum of array for right 
        for (int vals:nums){
            right += vals;
        }
        int mid = 0;
        while(left<=right){
            //calculates mid
            mid = left + (right-left)/2;
            //checks if mid is a valid answer
            if (cansplit(nums,k,mid)){
                right = mid-1;
            }
            //discard left subarray of answers
            else{
                left = mid+1;
            }
            //return lowest answer
        }
        return left;
        
        
    }
};