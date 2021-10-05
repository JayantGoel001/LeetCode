class Solution {
public:
    
    int soe(int n){
        int TOT = n;
        vector<bool> isPrime(TOT + 1,true);
        isPrime[0] = false;
        isPrime[1] = false;
        isPrime[2] = true;
        for(int i=2;i*i<=TOT;i++){
            if(isPrime[i]){
                for(int j = i*i;j<=TOT;j+=i){
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 2;i<TOT;i++){
            if(isPrime[i]){
                count++;
            }
        }
        return count;
    }
    
    
    int countPrimes(int n) {
        return soe(n);
    }
};