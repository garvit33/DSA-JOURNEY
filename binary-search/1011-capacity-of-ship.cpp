class Solution {
public:
//helper function checks valid answer
    bool cantransfer(vector<int>& weights, int days, int k) {
        int daysneed = 1;
        long count = 0;
        for (int i = 0; i < weights.size(); i++) {
        //if sum exceeds day increases
            if(count+weights[i]>k){
                daysneed++;
                count = weights[i];
            }
            //increases count
            else{
                count += weights[i];
            }

            }
            //returns valid or not
            return daysneed <= days;
        }
        int shipWithinDays(vector<int> & weights, int days) {
                int left = *max_element(weights.begin(),weights.end());
                int right = 0;
                //calculates sum of the array
                for (int val : weights) {
                    right += val;
                }
                int mid = left + (right - left) / 2;

                //loop while there is search space
                while (left <= right) {
                    //checks if mid is a valid answer
                    if (cantransfer(weights, days, mid)) {
                        right = mid - 1;
                    } 
                    //discared left array
                    else {
                        left = mid+1;
                    }

                    //calculates mid
                    mid = left + (right - left) / 2;
                }
                //return the answer
                return left;
        }
    
};