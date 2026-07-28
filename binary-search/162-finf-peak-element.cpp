class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         int left = 0;
        int right = nums.size()-1;
        int mid = std::midpoint(left,right);
        int peak = nums[mid];

//loop while there is a space to search
        while(left<right){
            //updates mid
            mid = std::midpoint(left,right);

            //checks if peak is guranteed in right 
            if(nums[mid]<nums[mid+1]){
                left = mid+1;                               
            }
            //removes the right half
            else{
                right = mid;
            }
            
        }
        //returns peak index
        return left;
        
        
    }
};