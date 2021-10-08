class Solution {
public:
    int minDis(string &word1, string &word2,int n1,int n2,int **dp){
        if(n1 == 0 && n2 == 0){
            return 0;
        }
        if(n1 == 0){
            return n2;
        }
        if(n2 == 0){
            return n1;
        }
        if(dp[n1][n2] != -1){
            return dp[n1][n2];
        }
        if(word1[n1-1] == word2[n2 - 1]){
            dp[n1][n2] = minDis(word1,word2,n1-1,n2-1,dp);
        }else{
            dp[n1][n2] = 1 + min(minDis(word1,word2,n1-1,n2-1,dp),min(minDis(word1,word2,n1,n2-1,dp),minDis(word1,word2,n1-1,n2,dp)));
        }
        return dp[n1][n2];
    }
    
    int minDistance(string &word1, string &word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        
        int **dp = new int*[size1 + 1];
        for(int i=0;i<=size1;i++){
            dp[i] = new int[size2 + 1];
        }
        for(int i=0;i<=size1;i++){
            for(int j=0;j<=size2;j++){
                dp[i][j] = -1;
            }
        }
        
        return minDis(word1,word2,size1,size2,dp);
    }
};