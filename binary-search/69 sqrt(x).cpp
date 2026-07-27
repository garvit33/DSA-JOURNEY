class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int mid  = 0;
        if(x==0){
            return 0;
        }
        //loop until there is space
        while (left<=right){
            //mid calculation
            mid = left + (right-left)/2;
            long long square = 1LL * mid*mid;

            //checks if mid is the answer
            if (square==x){
                return mid;
            }
            //discard right side of mid
            if(square > x){
                right = mid-1;
            }
            //discard left side of mid
            else{
                left = mid+1;
            }
            
        }
        //returns round figure ans
        return right;

    }
};