class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int i=0,n=0;

        while(i++<=k){
            n=(n*10+1)%k;
            if(n==0){
                return i;
            }
        }

       return -1;
    }
};