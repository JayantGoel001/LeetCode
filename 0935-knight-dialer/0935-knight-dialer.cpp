class Solution {
public:
    int MOD = 1e9 + 7;
    
    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }
        
        vector<vector<long>> A = {
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}
        };
        
        vector<vector<long>> v = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };
        
        n--;
        while (n > 0) {
            if ((n & 1) != 0) {
                v = multiply(v, A);
            }
            
            A = multiply(A, A);
            n >>= 1;
        }
        
        int ans = 0;
        for (long num : v[0]) {
            ans = (ans + num) % MOD;
        }
        
        return ans;
    }
    
    vector<vector<long>> multiply(vector<vector<long>>& A, vector<vector<long>>& B) {
        vector<vector<long>> result(A.size(), vector<long>(B[0].size(), 0));
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B[0].size(); j++) {
                for (int k = 0; k < B.size(); k++) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        
        return result;
    }
};