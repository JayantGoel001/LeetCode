class Solution {
public:
    int pivotInteger(int n) {
        int res = n * (n + 1) / 2;
        
        int x = sqrt(res);
        
        return x * x == res ? x : -1;
    }
};