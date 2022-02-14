class Solution {
public:
    vector<vector<string>> v;
    
    bool isSafe(vector<vector<char>> &_v,int row,int col,int n){
        for(int i=0;i<n;i++){
            if(_v[i][col] == 'Q'){
                return false;
            }
        }
        int x = row;
        int y = col;
        
        while(x>=0 && y>=0){
            if(_v[x][y] == 'Q'){
                return false;
            }
            x--;
            y--;
        }
        x = row;
        y = col;
        
        while(x < n && y < n){
            if(_v[x][y] == 'Q'){
                return false;
            }
            x++;
            y++;
        }
        x = row;
        y = col;
        
        while(x>=0 && y<n){
            if(_v[x][y] == 'Q'){
                return false;
            }
            x--;
            y++;
        }
        
        x = row;
        y = col;
        
        while(x<n && y>=0){
            if(_v[x][y] == 'Q'){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    
    void generateNQueen(int n,vector<vector<char>> &_v,int x=0){
        if(x == n){
            vector<string> __v;
            
            for(auto it : _v){
                string str = "";
                for(char ch : it){
                    str += ch;
                }
                __v.push_back(str);
            }
            v.push_back(__v);
        }else{
            for(int i=0;i<n;i++){
                if(isSafe(_v,x,i,n)){
                    _v[x][i] = 'Q';
                    generateNQueen(n,_v,x+1);
                    _v[x][i] = '.';
                }
            }
        }
            
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> _v;
        for(int i=0;i<n;i++){
            _v.push_back(vector<char>());
            for(int j=0;j<n;j++){
                _v[i].push_back('.');
            }
        }
        generateNQueen(n,_v);
        return v;
    }
};