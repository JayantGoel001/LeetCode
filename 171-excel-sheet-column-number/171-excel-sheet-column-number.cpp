class Solution {
public:
    int titleToNumber(string title) {
        long long p = 1;
        int res = 0;
        
        for(int i=title.size()-1;i>=0;i--){
            res += p * (title[i] - 'A' + 1);
            p *= 26L;
        }
        return res;
    }
};