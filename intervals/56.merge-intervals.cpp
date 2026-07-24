class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sorting the intervals
        sort(intervals.begin(),intervals.end());
        //answer array created
        vector<vector<int>> ans;
        int currentstart = intervals[0][0];
        int currentend = intervals[0][1];
        for (int i = 1;i<intervals.size();i++){
            //if overlapping
            if (currentend>=intervals[i][0]){
                currentend = max(currentend,intervals[i][1]);
                
                
            }
            //if not overlapping
            else{
                ans.push_back({currentstart,currentend});
                currentend = intervals[i][1]; 
                currentstart = intervals[i][0];

            }
        }
        ans.push_back({currentstart,currentend});
        return ans;
    }
};