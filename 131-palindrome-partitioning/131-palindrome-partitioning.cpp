class Solution {
public:
    vector<vector<string>> v;
    vector<vector<bool>> dp;
    void generateComb(string &s,vector<string> &temp,int start){
        if(start == s.size()){
            v.push_back(temp);
        }else{
            for(int i=start;i<s.size();i++){
                if(s[start] == s[i] && (i - start <= 2 || dp[start + 1][i - 1])){
                    dp[start][i] = true;
                    temp.push_back(s.substr(start,i - start + 1));
                    
                    generateComb(s,temp,i+1);
                    temp.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        int n = s.size();
        
        for(int i=0;i<=n;i++){
            dp.push_back(vector<bool>());
            for(int j=0;j<=n;j++){
                dp[i].push_back(false);
            }
        }
        generateComb(s,temp,0);
        
        return v;
    }
};