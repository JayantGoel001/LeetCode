class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        int count = 0;
        while(n){
            rev = rev * 2 + n%2;
            n /= 2;
            count++;
        }
        rev = rev * pow(2,32 - count);
        return rev;
    }
};