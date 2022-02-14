class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char x){
        for(int j=0;j<9;j++){
            if(board[row][j] == x){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[i][col] == x){
                return false;
            }
        }
        row -= row%3;
        col -= col%3;
        
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(board[i][j] == x){
                    return false;
                }
            }
        }
        return true;
    }
    bool sudoku(vector<vector<char>>& board,int row,int col){
        if(col == 9){
            return sudoku(board,row+1,0);
        }else if(row < 9){
            if(board[row][col] == '.'){
                for(int i=1;i<=9;i++){
                    if(isSafe(board,row,col,48 + i)){
                        board[row][col] = 48 + i;
                        if(sudoku(board,row,col + 1)){
                            return true;
                        }
                        board[row][col] = '.';
                    }
                }
                
                return false;
            }else{
                return sudoku(board,row,col+1);
            }
        }else if(row == 9){
            return true;
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board,0,0);
    }
};