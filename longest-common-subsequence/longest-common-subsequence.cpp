class Solution {
public:
    int getLCS(string &text1,string &text2,int n,int m,int **dp){
        if(n < 0 || m < 0){
            return 0;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        if(text1[n] == text2[m]){
            dp[n][m] = 1 + getLCS(text1,text2,n-1,m-1,dp);   
        }else{
            dp[n][m] = max(getLCS(text1,text2,n-1,m,dp),getLCS(text1,text2,n,m-1,dp));
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size();
        int s2 = text2.size();
        
        int **dp = new int*[s1];
        for(int i=0;i<s1;i++){
            dp[i] = new int[s2];
            for(int j=0;j<s2;j++){
                dp[i][j] = -1;
            }
        }
        return getLCS(text1,text2,s1-1,s2-1,dp);
    }
};