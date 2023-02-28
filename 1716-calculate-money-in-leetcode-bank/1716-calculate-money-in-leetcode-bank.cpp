class Solution {
public:
    int totalMoney(int n) {
        int x = n / 7;
        int t = n % 7;
        
        return (x * 7 * 8) / 2 + (x * (x - 1) * 7) / 2 + t * (2 * x + 2 + t - 1)/2;
    }
};