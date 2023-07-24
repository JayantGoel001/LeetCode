class Solution {
public:
    double static power(double x,int y){
        if(y==0){
            return 1.0;
        }else{
            if(y%2==0){
                return power(x*x,y/2);
            }else{
                return x * power(x*x,y/2);
            }
        }
    }
    double myPow(double x, int n) {
        
        double ans = power(x,abs(n));
        if(ans==0){
            return ans;
        }
        if(n<0){
            ans = 1.0/ans;
        }
        return ans;
    }
};