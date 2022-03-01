class Solution {
public:
    
    int getHappyNumber(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        while(n != 4 && n != 1){
            n = getHappyNumber(n);
        }
        return n == 1;
    }
};