class Solution {
public:
    int happy(int n){
        int sum = 0;
        while(n){
            int x = n % 10;
            
            sum += x * x;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int x = happy(n);
        while(x != 1 && x != 4){
            x = happy(x);
        }
        return x == 1;
    }
};