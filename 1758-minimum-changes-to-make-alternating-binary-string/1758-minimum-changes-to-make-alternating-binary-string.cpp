class Solution {
public:
    int minOperations(string s) {
        int start0 = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if (s[i] == '1') {
                    start0++;
                }
            } else {
                if (s[i] == '0') {
                    start0++;
                }
            }
        }
        
        return min(start0, (int) s.size() - start0);
    }
};