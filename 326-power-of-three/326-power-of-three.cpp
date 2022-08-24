class Solution {
public:
    bool isPowerOfThree(int n) {
        return n && pow(3,round(log(n)/log(3))) == n;
    }
};