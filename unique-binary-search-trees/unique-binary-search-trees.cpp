class Solution {
public:
    int numTrees(int n) {
        double_t res = 1;
        for(int i=n+1;i<=2*n;i++){
            res  = res * i;
        }
        for(int i=1;i<=n;i++){
            res /= i;
        }
        return ceil(res/(n+1));
    }
};