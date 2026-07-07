class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0, pow10 = 1;
        while (n > 0) {
            int d = n % 10;
            sum += d;
            if (d > 0) {
                x += d * pow10;
                pow10 *= 10;
            }
            n /= 10;
        }
        return x * sum;
    }
};