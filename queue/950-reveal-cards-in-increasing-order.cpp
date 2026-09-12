class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        //sorts the decks 
        sort(deck.begin(),deck.end());
        deque<int> dq;
        vector<int> ans(deck.size());
        //storing index from 0 to size in deque
        for(int i=0;i<deck.size();i++){
            dq.push_back(i);
        }
        for(int card:deck){
            int index = dq.front();
            dq.pop_front();
            ans[index] = card;
            //skips next card if exists and push it to the end 
            if(!dq.empty()){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        return ans;
    }
};