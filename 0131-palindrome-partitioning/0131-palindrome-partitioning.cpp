class Solution {
public:
    vector<vector<string>> v;
    vector<vector<bool>> dp;
    
    void DFS(string &s, vector<string> &cur, int pos){
        if(pos == s.size()){
            v.push_back(cur);
            return;
        }
        for(int i = pos;i<s.size();i++){
            if(s[pos] == s[i] && (i - pos <= 2 || dp[pos + 1][i - 1])){
                dp[pos][i] = true;
                
                cur.push_back(s.substr(pos, i - pos + 1));
                DFS(s, cur, i + 1);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        dp.resize(s.size(), vector<bool> (s.size(), false));
        DFS(s, cur, 0);
        
        return v;
    }
};