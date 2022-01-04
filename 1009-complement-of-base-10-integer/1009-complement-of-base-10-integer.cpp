class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        int num = floor(log2(n)) + 1;
        
        return pow(2,num) - n - 1;
    }
};