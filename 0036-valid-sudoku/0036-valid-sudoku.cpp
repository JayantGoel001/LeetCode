class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_map<char,int> mp;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    mp[board[i][j]]++;
                }
                if(mp[board[i][j]] > 1){
                    return false;
                }
            }
        }
        for(int i=0;i<9;i++){
            unordered_map<char,int> mp;
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    mp[board[j][i]]++;
                }
                if(mp[board[j][i]] > 1){
                    return false;
                }
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                unordered_map<char,int> mp;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(board[k][l]!='.'){
                            mp[board[k][l]]++;
                        }
                        if(mp[board[k][l]] > 1){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};