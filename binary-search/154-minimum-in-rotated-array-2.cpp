class Solution {
public:
//binary search
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = left+(right-left)/2;
        int minimum = nums[mid];
        //loops while left right dont overlaps
        while(left<=right){
            //mid calculation
            mid = left+(right-left)/2;
            //shift search space to left
            if(nums[mid] < nums[right] ){
                right = mid;
            }
            //shift search space to left
            else if(nums[mid] > nums[right]){
                left = mid+1;
            }
            //if duplicate found reduce the search space by removing the duplicate mid is there is that is the answer
            else{right--;}
            minimum = min(minimum,nums[mid]);
        }
        return minimum;
    }
};