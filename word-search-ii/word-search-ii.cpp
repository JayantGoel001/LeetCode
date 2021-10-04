class Solution {
public:
    bool isSafe(int x,int y,int n,int m){
        return x>=0 && y>=0 && x<n && y<m;
    }
    bool check(vector<vector<char>>& board,string &word,int x,int y,int it,int n,int m){
        if(it == word.size()){
            return true;
        }
        if(isSafe(x,y,n,m) && board[x][y] != '#'){
            if(board[x][y] != word[it]){
                return false;
            }
            char temp = board[x][y];
            board[x][y] = '#';
            
            if(check(board,word,x-1,y,it + 1,n,m)){
                board[x][y] = temp;
                return true;
            }
            if(check(board,word,x+1,y,it + 1,n,m)){
                board[x][y] = temp;
                return true;
            }
            if(check(board,word,x,y-1,it + 1,n,m)){
                board[x][y] = temp;
                return true;
            }
            if(check(board,word,x,y+1,it + 1,n,m)){
                board[x][y] = temp;
                return true;
            }
            board[x][y] = temp;
            return false;
        }
        return false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> s;
        int n = board.size();
        int m = board[0].size();
        set<char> b;
        
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                b.insert(board[i][j]);
            }
        }
        
        
        for(auto word : words){
            bool flag = false;
            for(auto ch : word){
                if(b.find(ch) == b.end()){
                    flag = true;
                    break;
                }
            }
            
            if(flag){
                continue;
            }
            
            for(int i=0;i<n;i++){
                for(int j = 0;j<m;j++){
                    if(board[i][j] == word[0] && check(board,word,i,j,0,n,m)){
                        s.insert(word);
                    }
                }
            }
        }
        vector<string> v(s.begin(),s.end());
        return v;
    }
};