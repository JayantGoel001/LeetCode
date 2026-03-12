class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while(a || b || c) {
            
            if (!(a % 2 && b % 2 && c % 2)) count += abs(a % 2 + b % 2 - c % 2);

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return count;
    }
};