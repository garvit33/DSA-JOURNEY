class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        //set containing bob sizes
        unordered_set<int> bob;
        for(int x : bobSizes){
            bob.insert(x);
        }
        //doing sum of alice and bob candy boxes
        int alicesum = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int bobsum = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        //this is the difference we need between exchanged boxes
        int diff = (alicesum-bobsum)/2;
        //checks if bob contains alice - diff box 
        for(int x:aliceSizes){
            int required = x - diff;
            if(bob.count(required)){
                return{x,required};
            }
        }
        return{};
    }

};