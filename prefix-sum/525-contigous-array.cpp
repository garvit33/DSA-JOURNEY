class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> firstocc;
        int sum = 0;
        int count = 0;
        int maxlen = 0;
        firstocc[0] = -1;
        for(int i = 0;i<nums.size();i++){
            nums[i] == 0 ? sum+=-1 : sum+=1;
            if(firstocc.find(sum) == firstocc.end()){
                firstocc[sum] = i;      
            }
            else{
                count= i-firstocc[sum];
                maxlen = max(maxlen,count);
        }
        }
        return maxlen;
    }
};