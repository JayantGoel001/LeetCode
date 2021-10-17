class Solution {
public:
    long long int power(long long int x,int y){
        if(y == 0){
            return 1;
        }else{
            if(y%2==0){
                return power(x*x,y/2);
            }else{
                return x * power(x*x,(y-1)/2);   
            }
        }
    }
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false;
        }
        int x = log(n)/log(2);
        
        return power(2,x) == n;
    }
};