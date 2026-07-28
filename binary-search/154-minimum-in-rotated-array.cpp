class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = std::midpoint(left,right);
        int minimum = nums[mid];

//loop while there is a space to search
        while(left<=right){
            //updates mid
            mid = std::midpoint(left,right);
            //checks if right half is sorted
            if(nums[mid]<=nums[right]){
                right = mid-1;
            }
            //executes if right half isnt sorted
            else{
                left = mid+1;
            }
            //calculates minimum
            minimum = min(nums[mid],minimum);
        }
        return minimum;
    }
};