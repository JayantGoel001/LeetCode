class Solution {
public:
    double power(double x, int y){
        if(y == 1){
            return x;
        }
        if(y % 2 == 0){
            return power(x * x, y/2);
        }else{
            return x * power(x * x, y/2);
        }
    }
    int climbStairs(int n) {
        return round(power((sqrt(5.0) + 1.0)/2.0, n + 1)/sqrt(5.0));
    }
};