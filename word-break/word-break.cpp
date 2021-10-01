class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        sort(wordDict.begin(),wordDict.end());
        
        int ssize = s.size();
        bool dp[ssize+1];
        
        for(int i=0;i<=ssize;i++){
            dp[i] = false;
        }
        dp[0] = true;
        
        int size = wordDict.size();
        for(int i=1;i<=ssize;i++){
            for(int j=0;j<i;j++){
                string str = s.substr(j,i-j);
                int pos = lower_bound(wordDict.begin(),wordDict.end(),str) - wordDict.begin();
                if(dp[j] && pos!=size && wordDict[pos] == str){
                    dp[i] = true;
                }
            }
        }
        return dp[ssize];
    }
};