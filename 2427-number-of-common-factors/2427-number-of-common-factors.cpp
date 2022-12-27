class Solution {
public:
    int commonFactors(int a, int b) {
        int count = 0;
        for(int i=1;i<=min(a,b);i++){
            count += (a%i==0) && (b%i==0);
        }
        return count;
    }
};