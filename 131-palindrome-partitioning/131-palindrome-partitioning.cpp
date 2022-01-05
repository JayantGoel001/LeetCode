class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len,vector<bool> (len,false));
        vector<vector<string>> result;
        vector<string> curr;
        dfs(s,0,curr,result,dp);
        return result;
    }
    
    void dfs(string s,int start,vector<string> &cur,vector<vector<string>> &res,vector<vector<bool>> &dp){
        if(s.length() == start){
            res.push_back(cur);
        }
        for(int i = start;i<s.length();i++){
            if(s[start] == s[i] && (i - start <= 2 || dp[start + 1][i - 1])){
                dp[start][i] = true;
                cur.push_back(s.substr(start,i - start + 1));
                dfs(s,i+1,cur,res,dp);
                cur.pop_back();
            }
        }
    }
};