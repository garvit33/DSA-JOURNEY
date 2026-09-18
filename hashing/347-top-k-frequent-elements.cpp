class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //stores freq of elements
        unordered_map<int,int> freq;
        
        vector<int> ans;
        //calculates freq of all elements
        for(int i = 0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        //remove the highest freq element repeating k times
        for(int i = 0;i<k;i++){
            int maxfreq = 0;
            int maxelement = 0;
            //getting the highest freq element
            for(auto& [element,freq] : freq){
                if(freq>maxfreq){
                    maxfreq = freq;
                    maxelement = element;
                }
            }
            ans.push_back(maxelement);
            freq.erase(maxelement);
        }
        return ans;
    }
};