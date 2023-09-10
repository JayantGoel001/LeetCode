class Solution {
public:
    int countOrders(int n) {
        long long prod = 1;
        int MOD = 1e9 + 7;
        for(int i=1;i<=n;i++){
            prod = (prod * ((long long)i * (2 * i - 1)%MOD)%MOD);
        }
        return prod;
    }
};