class Solution {
public:
    bool wordBreak(string &s, vector<string>& wordDict) {
        int size = s.size();
        sort(wordDict.begin(),wordDict.end());
        vector<bool> dp(size+1,false);
        
        dp[0]=true;
        int n = wordDict.size();
        for(int i =1;i<=size;i++){
            for(int j =0;j<i;j++){
                string str = s.substr(j,i-j);
                auto pos = lower_bound(wordDict.begin(),wordDict.end(),str);
                if(dp[j] && pos!=wordDict.end() && wordDict[pos - wordDict.begin()] == str){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[size];
    }
};