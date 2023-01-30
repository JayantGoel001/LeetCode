class Solution {
public:
    int tribonacci(int n) {
        vector<int> f(max(3, n + 1), 0);
        f[0] = 0;
        f[1] = 1;
        f[2] = 1;
        
        for(int i=3;i<=n;i++){
            f[i] = f[i - 3] + f[i - 2] + f[i - 1];
        }
        return f[n];
    }
};