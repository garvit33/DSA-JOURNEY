class Solution {
public:
    vector<int> curr;
    vector<vector<int>> ans;
    void solver(int start,int n,int k){
        if(curr.size() == k){
            ans.push_back({curr});
        }

        for(int i = start;i<=n;i++){
            curr.push_back(i);

            solver(i+1,n,k);

            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        solver(1,n,k);

        return ans;
    }
};