class Solution {
public:
    void DFS(vector<vector<int>>& isConnected,int u,vector<bool> &isVis,int n){
        isVis[u] = true;
        
        for(int i =0;i<n;i++){
            if(isConnected[u][i] == 1 && !isVis[i]){
                DFS(isConnected,i,isVis,n);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<bool> isVis(n,false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!isVis[i]){
                count++;
                
                DFS(isConnected,i,isVis,n);
            }
        }
        return count;
    }
};