class Solution {
public:
    bool isSafe(int x,int y,int n,int m){
        return x>=0 && y>=0 && x<n && y<m;
    }
    bool check(vector<vector<char>>& board,string &word,int x,int y,int it,int n,int m,vector<vector<bool>> &dp){
        if(it == word.size()){
            return true;
        }
        if(isSafe(x,y,n,m) && !dp[x][y]){
            if(board[x][y] != word[it]){
                return false;
            }
            
            dp[x][y] = true;
            
            if(check(board,word,x-1,y,it + 1,n,m,dp)){
                return true;
            }
            if(check(board,word,x+1,y,it + 1,n,m,dp)){
                return true;
            }
            if(check(board,word,x,y-1,it + 1,n,m,dp)){
                return true;
            }
            if(check(board,word,x,y+1,it + 1,n,m,dp)){
                return true;
            }
            dp[x][y] = false;
            return false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == word[0] && check(board,word,i,j,0,n,m,dp)){
                    return true;
                }
            }
        }
        return false;
    }
};