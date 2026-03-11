class Solution {
public:
    void combination(int k, int n, int prev,vector<vector<int>> &res, vector<int> &temp) {
        if (n == 0 && temp.size() == k) {
            res.push_back(temp);
            return;
        }
        if (temp.size() == k) return;

        for(int i=prev+1;i<=9;i++) {
            temp.push_back(i);
            combination(k, n - i, i, res, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        combination(k, n, 0, res, temp);
        return res;
    }
};