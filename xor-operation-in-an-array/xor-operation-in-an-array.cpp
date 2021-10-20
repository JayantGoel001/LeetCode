class Solution {
public:
    int xorOpB(int n,int start){
        if(n%2==0){
            return (n/2) & 1;
        }else{
            return ((n/2) & 1) ^ (start + n - 1);
        }
    }
    int xorOp(int n,int start){
        if(start&1){
            return (start - 1) ^ xorOpB(n+1,start-1);
        }else{
            return xorOpB(n,start);
        }
    }
    int xorOperation(int n, int start) {
        int res = 2 * xorOp(n,start/2);
        
        if(n & start & 1){
            res++;
        }
        return res;
    }
};