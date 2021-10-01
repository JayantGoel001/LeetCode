class Solution {
public:
    double power(double x,int y){
        if(y==0){
            return 1;
        }else{
            if(y%2==0){
                return power(x*x,y/2);
            }else{
                return x * power(x*x,(y-1)/2);
            }
        }
    }
    int climbStairs(int n) {
        double phi = (sqrt(5) + 1.0)/2.0;
        return round(power(phi,n+1)/sqrt(5.0));
    }
};