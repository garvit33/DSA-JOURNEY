int searchInsert(int* nums, int numsSize, int target) {
    int right = numsSize-1;
    int left = 0;
    int mid = 0;
//loop till elements are there to compare
    while(left<=right){
        //calculates mid
        mid = left + (right-left)/2;
        //returns mif if equal to tgt
        if (nums[mid]==target){
            return mid;
        }
        //shirft to  left window
        if (nums[mid]>target){
            right = mid-1;
        }
        //shift to right window 
        else{
            left = mid+1;
        }
    }
    //returns expected position if not found
    return left;

    
}