class Solution {
public:
    int countTriples(int n) {
        vector<bool> v(n * n + 1, false);
        for(int i=1;i <= n;i++){
            v[i * i] = true;
        }
        int count = 0;
        for(int i = 1;i < n;i++){
            for(int j = i + 1; j < n && i * i + j * j <= n * n;j++){
                count += v[i * i + j * j] * 2;
            }
        }
        return count;
    }
};