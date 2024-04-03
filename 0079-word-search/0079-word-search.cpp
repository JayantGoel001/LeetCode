class Solution {
public:
    bool DFS(vector<vector<char>>& board, string &word,int i,int j,int n,int m,int x=0){
        if(x == word.size()){
            return true;
        }
        if(i >= 0 && j >= 0 && i < n && j < m && board[i][j] == word[x]){
            char ch = board[i][j];
            board[i][j] = '#';
            
            bool d1 = DFS(board,word,i-1,j,n,m,x + 1);
            bool d2 = DFS(board,word,i,j-1,n,m,x + 1);
            bool d3 = DFS(board,word,i+1,j,n,m,x + 1);
            bool d4 = DFS(board,word,i,j+1,n,m,x + 1);
            
            board[i][j] = ch;
            
            return d1 || d2 || d3 || d4;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(DFS(board,word,i,j,n,m)){
                    return true;
                }
            }
        }
        return false;
    }
};