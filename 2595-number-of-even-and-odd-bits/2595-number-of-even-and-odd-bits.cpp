class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> v(2,0);
        bool odd = false;
        
        while(n){
            v[odd] += (n&1) == 1;
            n >>= 1;
            odd = !odd;
        }
        
        return v;
    }
};