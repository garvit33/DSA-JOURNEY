class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //main freq map made wit words freq
        unordered_map<string,int> freq;

        int wordlen = words[0].size();
        vector<int> ans;

        //storingn freq of each word 
        for(auto str:words){
            freq[str]++;
        }

        //outer loop for testing all offsets for example there is a offset xfoo then x is a offset
        for(int i = 0;i<wordlen;i++){
            unordered_map<string,int> window;   
            int left = i;   
            int count = 0;

            for(int right = i;right+wordlen <= s.size();right += wordlen){
                string curr = s.substr(right,wordlen);

                //if word is included in words then push else reset the left to right 
                if(freq.find(curr) != freq.end()){  
                    window[curr]++;
                    count++;

                    //shrinking if a frequency of a word exceeds 
                    while(window[curr]>freq[curr]){
                        string shrink = s.substr(left,wordlen);
                        window[shrink]--;
                        count--;
                        
                        left+=wordlen;
                    }
                    
                    //if count which is number of words in window is equa then push the starting index of that subarray
                    if(count == words.size()){
                        ans.push_back(left);
                    }

                }

                //resseting logic of left and map 
                else{
                    left = right+wordlen;
                    window.clear();
                    count = 0;
                    }
        }
        }
       return ans;
    }
};