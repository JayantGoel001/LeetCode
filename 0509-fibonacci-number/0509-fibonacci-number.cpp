class Solution {
public:
    double power(double x, int y){
        if(y == 0){
            return 1.0;
        }
        if(y % 2 == 0){
            return power(x * x, y/2);
        }else{
            return x * power(x * x, y/2);
        }
    }
    
    int fib(int n) {
        return round(power((sqrt(5.0) + 1.0)/2.0, n)/sqrt(5.0));    
    }
};