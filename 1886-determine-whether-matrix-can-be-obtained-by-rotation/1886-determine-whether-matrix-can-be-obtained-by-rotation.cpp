class Solution {
public:
    
    void rotate(vector<vector<int>>&m){
        int n = m.size();
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                swap(m[i][j], m[j][i]);
        
        for(int i = 0; i < n; i++){
            reverse(m[i].begin(), m[i].end());
        }
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
     
        if(mat == target) return true;
        
        for(int i = 0; i < 3; i++){
            rotate(mat);
            if(mat == target) return true;
        }
        return false;
    }
    
    
};