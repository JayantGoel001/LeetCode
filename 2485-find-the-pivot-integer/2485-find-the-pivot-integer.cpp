class Solution {
public:
    int pivotInteger(int n) {
        int rsum = (n * (n + 1))/2;
        
        int lsum = 0;
        for(int i=1;i<=n;i++){
            lsum += i;
            
            if(lsum == rsum){
                return i;
            }
            rsum -= i;
        }
        return -1;
    }
};