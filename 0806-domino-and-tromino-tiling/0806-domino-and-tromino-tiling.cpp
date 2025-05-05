class Solution {
public:
    int numTilings(int n) {
        long MOD = 1000000007;
        if (n <= 2) {
            return n;
        }
        long fCurrent = 5L;
        long fPrevious = 2L; 
        long fBeforePrevious = 1L; 
        for (int k = 4; k < n + 1; ++k) {
            long tmp = fPrevious;
            fPrevious = fCurrent; 
            fCurrent = (2 * fCurrent + fBeforePrevious) % MOD;
            fBeforePrevious = tmp;
        }
        return static_cast<int>(fCurrent);
    }
};