class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0;
        int right = k-1;
        int sum = 0;
        int subarrays = 0;
        //calculates sum of first window
        for(int i = 0; i<k;i++){
            sum += arr[i];
        }
        //checks if its a valid window
        if (sum/k >= threshold){
            subarrays++;
        }
        //move for next windows
        for(int i = k;i<arr.size();i++){
            //adds next element in window
            sum += arr[i];
            //removes previous element in window
            sum -= arr[i-k];
        
            if(sum/k >= threshold){
                subarrays++;
            }
        }
        return subarrays;
    }
};