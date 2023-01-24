class Solution {
public:
    int alternateDigitSum(int n) {
        bool sign = (int)floor(log10(n) + 1) % 2;
        
        int sum = 0;
        while(n){
            sum = sum + (sign ? n%10 : -n%10);
            n /= 10;
            sign = !sign;
        }
        return sum;
    }
};