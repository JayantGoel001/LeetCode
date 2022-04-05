class Solution {
public:
    int arrangeCoins(int n) {
        int x = (sqrt(8 * (double)n  + 1) - 1)/2;
        return x;
    }
};