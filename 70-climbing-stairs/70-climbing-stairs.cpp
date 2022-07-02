class Solution {
public:
    double power(double x,int n){
        if(n == 0){
            return 1;
        }
        if(n%2 == 0){
            return power(x * x, n/2);
        }else{
            return x * power(x * x, (n - 1)/2);
        }
    }
    int climbStairs(int n) {
        return round(power((sqrt(5) + 1.0)/2.0, n + 1)/sqrt(5));
    }
};