class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        while(n){
            int x = n%10;
            prod *= x;
            sum += x;
            n /= 10;
        }
        return prod - sum;
    }
};