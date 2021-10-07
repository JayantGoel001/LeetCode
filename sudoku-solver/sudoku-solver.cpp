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
    bool sudoku(vector<vector<char>>& board,int x,int y,int row,int col){
        if(x == row){
            return true;
        }else if(y == col){
            return sudoku(board,x+1,0,row,col);
        }else{
            if(board[x][y] == '.'){
                for(int i=1;i<=9;i++){
                    board[x][y] = i + '0';
                    if(isSafe(board,x,y,row,col)){
                        if(sudoku(board,x,y+1,row,col)){
                            return true;
                        }
                    }
                    board[x][y] = '.';
                }
                return false;
            }else{
                return sudoku(board,x,y+1,row,col);
            }
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        int row = board.size();
        int col = board[0].size();
        
        sudoku(board,0,0,row,col);
        
    }
};