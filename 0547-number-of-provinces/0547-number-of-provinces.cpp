class Solution {
public:
    void DFS(vector<vector<int>>& isConnected,vector<bool> &vis,int i){
        vis[i] = true;
        for(int j=1;j<=isConnected.size();j++){
            if(!vis[j] && isConnected[i-1][j-1]){
                DFS(isConnected, vis, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       vector<bool> vis(isConnected.size() + 1, false) ;
        
        int count = 0;
        for(int i=1;i<=isConnected.size();i++){
            if(!vis[i]){
                DFS(isConnected, vis, i);
                count++;
            }
        }
        return count;
    }
};