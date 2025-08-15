class Solution {
public:
    bool isPowerOfFour(int n) {
        return n && n == pow(4, round(log(n)/log(4.0)));
    }
};