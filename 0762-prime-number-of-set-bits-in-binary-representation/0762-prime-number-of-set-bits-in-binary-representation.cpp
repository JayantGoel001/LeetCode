class Solution {
public:
    bool isPrime(int n){
        return n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19;
    }
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for(int i=left;i<=right;i++){
            int num = i;
            
            int bits = 0;
            while(num){
                bits += num & 1;
                num >>= 1;
            }
            count += isPrime(bits);
        }
        return count;
    }
};