class Solution {
public:
    int countTriples(int n) {
        vector<bool> v(n * n + 1, false);
        for(int i=1;i <= n;i++){
            v[i * i] = true;
        }
        int count = 0;
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                count += (i * i + j * j <= n * n && v[i * i + j * j]);
            }
        }
        return count;
    }
};