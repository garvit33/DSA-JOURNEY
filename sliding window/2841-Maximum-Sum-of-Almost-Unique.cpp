class Solution {
public:
    
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int,int> freq;
        long long sum = 0;
        long long bestsum = 0;
        int left = 0;

        //right pointer 
        for(int right = 0;right<nums.size();right++){
            //counts frequency and calculates sum of windows
            freq[nums[right]]++;
            sum+=nums[right];
        
        //if window exceeds k left is removed from the window and increased
            if(right - left +1 >k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0){
                    freq.erase(nums[left]);
                }
                sum -= nums[left];
                left++;
            }
            //if window size is valid count sum 
            if(right-left+1 == k){
                if(freq.size()>=m){
                    bestsum = max(bestsum,sum);
                }
            }
        }
        return bestsum;
    }
};