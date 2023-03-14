class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = board.size();
        int m = board.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'R'){
                    int count = 0;
                    
                    for(int k = i - 1;k >= 0 && board[k][j] != 'B';k--){
                        if(board[k][j] == 'p'){
                            count++;
                            break;
                        }
                    }
                    for(int k = i + 1;k < board.size() && board[k][j] != 'B';k++){
                        if(board[k][j] == 'p'){
                            count++;
                            break;
                        }
                    }
                    for(int k = j - 1;k >= 0 && board[i][k] != 'B';k--){
                        if(board[i][k] == 'p'){
                            count++;
                            break;
                        }
                    }
                    for(int k = j + 1;k < board.size() && board[i][k] != 'B';k++){
                        if(board[i][k] == 'p'){
                            count++;
                            break;
                        }
                    }
                    
                    return count;
                }
            }
        }
        return 0;
    }
};