class Solution {
public:
    void generateCombination(int n, vector<string> &res, string &str, int open, int close) {
        if (open == n && close == n) {
            res.push_back(str);
            return;
        }

        if (open < n) {
            str.push_back('(');
            generateCombination(n, res, str, open + 1, close);
            str.pop_back();
        } 
        if (close < open) {
            str.push_back(')');
            generateCombination(n, res, str, open, close + 1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str = "";
        generateCombination(n, res, str, 0, 0);
        return res;
    }
};