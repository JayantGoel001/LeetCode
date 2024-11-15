class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& n){
        int sz = n.size(), r = sz - 1;
        for (; r > 0 && n[r - 1] <= n[r]; --r) ;
        auto res = r;
        for (int l = 0; l < r && (l == 0 || n[l - 1] <= n[l]); ++l) {
            while (r < sz && n[r] < n[l])
                ++r;
            res = min(res, r - l - 1);
        }
        return res;
    }  
};