class Solution {
public:
    vector<int> output,count;
    
    void DFS(vector<int> *adj,int u,int parent){
        for(auto it : adj[u]){
            if(it != parent){
                DFS(adj,it,u);
                
                count[u] += count[it];
                output[u] += output[it] + count[it];
            }
        }
    }
    
    void DFS2(vector<int> *adj,int u,int parent,int n){
        for(auto it : adj[u]){
            if(it != parent){
                output[it] = output[u] - count[it] + n - count[it];
                
                DFS2(adj,it,u,n);
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            output.push_back(0);
            count.push_back(1);
        }
        DFS(adj,0,-1);
        DFS2(adj,0,-1,n);
        
        return output;
    }
};