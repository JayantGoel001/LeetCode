class Solution {
public:
    bool checkString(vector<vector<char>>& board,int x,int y,int n,int m, string &word,vector<vector<bool>> &dp,int a){
        if(a == word.size()){
            return true;
        }else{
            if(x>=0 && y>=0 && x < n && y < m && word[a] == board[x][y] && !dp[x][y]){
                dp[x][y] = true;
                bool r1 = checkString(board,x+1,y,n,m,word,dp,a+1);
                bool r2 = checkString(board,x-1,y,n,m,word,dp,a+1);
                bool r3 = checkString(board,x,y-1,n,m,word,dp,a+1);
                bool r4 = checkString(board,x,y+1,n,m,word,dp,a+1);
                dp[x][y] = false;
                
                return r1 || r2 || r3 || r4;
            }else{
                return false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0] && checkString(board,i,j,n,m,word,dp,0)){
                    return true;
                }
            }
        }
        return false;
    }
};