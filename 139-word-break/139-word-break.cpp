class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1,false);
        dp[0] = true;
        
        for(int i=0;i<=s.size();i++){
            for(auto it : wordDict){
                if(dp[i] && it == s.substr(i,it.size())){
                    dp[i + it.size()] = true;
                }
            }
        }
        return dp[s.size()];
    }
};