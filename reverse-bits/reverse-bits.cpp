class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = 0;
        int count = 0;
        while(n){
            x = x * 2 + n%2;
            n = n/2;
            count++;
        }
        x = x * pow(2,32-count);
        return x;
    }
};