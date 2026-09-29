class Solution {
public:
    double solve(double x,long long n){

        if(n==2)return x*x;
        
        if(n==0)return 1;

        //if even
        if(n%2 == 0){

            //split in half powers and multiply 
            double half = solve(x,n/2);
            return half*half;
        }
        
        //if odd power
        else{
            
            //we do same we did with n-1 and later multiply x 
            double half = solve(x,(n-1)/2);
            return half*half*x;
        }

    }
    double myPow(double x, int n) {
        // converting n into double
        long long N = n;

        //if n is negative 
        if(N<0){
            return 1.00/solve(x,-N); 
        }

        return solve(x,N);
    }
};