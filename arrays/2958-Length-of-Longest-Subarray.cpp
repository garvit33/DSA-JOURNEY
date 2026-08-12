class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int left = 0;
        int bestlength = 0;
        int windowlength = 0;

        for(int right = 0;right<nums.size();right++){
            //updates freq of right element
            freq[nums[right]]++;
            //shrinks window if freq exceeds k
                while(freq[nums[right]] > k){
                    freq[nums[left]]--;
                    left++;
                
            }
            //calculates window length
            windowlength = (right-left)+1;
            //stores best window length
            bestlength = max(bestlength,windowlength);
        }


    return bestlength;
   }
};