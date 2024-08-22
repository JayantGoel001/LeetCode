class Solution {
public:
    int findComplement(int num) {
        int n = floor(log2(num)) + 1;
        
        return pow(2,n) - num - 1;
    }
};