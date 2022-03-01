class Solution {
public:
    
    bool DFS(vector<vector<char>>& board, string &word,int i,int j,int x){
        if(x == word.size()){
            return true;
        }
        if(i>=0 && j>=0 && i < board.size() && j < board[0].size() && board[i][j] == word[x]){
            char ch = board[i][j];
            board[i][j] = '#';
            
            bool d1 = DFS(board,word,i+1,j,x+1);
            bool d2 = DFS(board,word,i,j+1,x+1);
            bool d3 = DFS(board,word,i-1,j,x+1);
            bool d4 = DFS(board,word,i,j-1,x+1);
            
            board[i][j] = ch;
            
            return d1 || d2 || d3 || d4;
        }
        return false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<char> b;
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                b.insert(board[i][j]);
            }
        }
        set<string> s;
        for(auto word : words){
            bool flag = true;
            
            for(auto it : word){
                if(b.find(it) == b.end()){
                    flag = false;
                    break;
                }
            }
            if(flag){
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(board[i][j] == word[0] && DFS(board,word,i,j,0)){
                            s.insert(word);
                        }
                    }
                }
            }
        }
        return vector<string> (s.begin(),s.end());
    }
};