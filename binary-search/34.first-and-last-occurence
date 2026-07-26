class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       
        vector <int> ans(2,0);
        int left = 0;
        int right = nums.size()-1;
        int mid = left+ (right - left)/2;
        int first = -1;
        int last = -1;

        //if no elements
        if (nums.size()==0){
            ans[0] = first;
            ans[1] = last;
            return ans;
        }
        //first binary search for first occurence
        while (left<=right){
            mid = left+ (right - left)/2;

            if (nums[mid] == target){
                first = mid;
                right = mid-1;
                

            }
            if (nums[mid]>target){
                right = mid-1;
            }
            if(nums[mid]<target){
                left = mid+1;
            }
        }
        ans[0] = first;
        right = nums.size()-1;
        left = 0;
//second binary search for last occurence
          while (left<=right){
            mid = left+ (right - left)/2;

            if (nums[mid] == target){
                last = mid;
                left = mid+1;
                

            }
            if (nums[mid]>target){
                right = mid-1;
            }
            if(nums[mid]<target){
                left = mid+1;
            }
        }
        ans[1] = last;



        
    return ans;
    }
};