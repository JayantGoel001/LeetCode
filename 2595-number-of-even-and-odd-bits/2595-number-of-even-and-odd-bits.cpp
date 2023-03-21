class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> v(2,0);
        bool odd = false;
        
        while(n){
            v[odd] += n%2 == 1;
            n /= 2;
            odd = !odd;
        }
        
        return v;
    }
};