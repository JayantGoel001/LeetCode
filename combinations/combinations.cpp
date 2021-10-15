class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res{};
        vector<int> comb{};
        combineHelper(res, 1, n, k, comb);
        return res;
    }
    
    void combineHelper(vector<vector<int>>& res, int cur, int n, int k, vector<int>& comb) {
        if(k == 0) {
            res.push_back(comb);
            return;
        }
        for(int i = cur; i <= n-k+1; i++) {
            comb.push_back(i);
            combineHelper(res, i+1, n, k-1, comb);
            comb.pop_back();
        }
    }
}; 