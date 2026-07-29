class Solution {
public:
//helper function to check if the speed is valid
    bool canfinish(vector<int>&piles,int k,int h){
        long long hoursneed = 0;
        
        for (int i = 0; i<piles.size();i++){
            hoursneed += piles[i]/k;
            if(piles[i]%k != 0){
                hoursneed++;              
        }
    }
            return hoursneed<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        int mid = 0;
        
//loop until there is space in answer array
        while(left<=right){
            mid = left + (right - left)/2;
            //checks if mid is a valid answer
            if (canfinish(piles,mid,h)){
                
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

    //returns lowest valid speed 
    return left;
    }
};