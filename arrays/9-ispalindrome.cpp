class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;   
        }
        long long reverse = 0;
        int digit = 0;
        int original = x;
        while(original>0){
            digit = original%10;
            original = original/10;
            reverse = reverse*10+digit;
        }
        if(x == reverse){
            return true;
        }
        return false;
    }
};