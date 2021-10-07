class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int x,int y,int row,int col){
        unordered_map<char,int> mp;
        
        for(int i = 0;i<9;i++){
            if(board[i][y] != '.'){
                mp[board[i][y]]++;
                if(mp[board[i][y]] > 1){
                    return false;
                }
            }
        }
        mp.clear();
        
        for(int i = 0;i<9;i++){
            if(board[x][i] != '.'){
                mp[board[x][i]]++;
                if(mp[board[x][i]] > 1){
                    return false;
                }
            }
        }
        mp.clear();
        int _x = x - x%3;
        int _y = y - y%3;
        
        for(int i=_x;i<_x + 3;i++){
            for(int j=_y;j<_y + 3;j++){
                if(board[i][j] != '.'){
                    mp[board[i][j]]++;
                    if(mp[board[i][j]] > 1){
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!isSafe(board,i,j,r,c)){
                    return false;
                }
            }
        }
        return true;
    }
};