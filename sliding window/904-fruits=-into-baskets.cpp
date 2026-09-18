class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //stores frequency of types of fruits in a window
        unordered_map<int,int> freq;
        int left = 0;
        int maxtree = 0;
        
        //right pointer of window 
        for(int right = 0;right<fruits.size();right++){
            
            freq[fruits[right]]++;
            //if frequency increase more than 2 we shrink from left 
            while(freq.size()>2){
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0){
                    freq.erase(fruits[left]);
                }
                //left pointer of window 
                left++;
            }
            //if its a valid window we count its max trees
            if(freq.size()<=2){
                int trees = right-left+1;
                maxtree = max(trees,maxtree);
            }
        }
        return maxtree;
    }
};