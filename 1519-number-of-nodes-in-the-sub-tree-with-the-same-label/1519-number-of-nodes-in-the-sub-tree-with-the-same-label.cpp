class Solution {
public:
    vector<int> ans;
    
    vector<int> DFS(vector<vector<int>> &adj, string &labels, int u, int parent){
        
        vector<int> temp(26,0);
        temp[labels[u] - 'a'] += 1;
        
        for(auto it : adj[u]){
            if(it != parent){
                vector<int> child = DFS(adj, labels, it, u);
                
                for(int i=0;i<26;i++){
                    temp[i] += child[i];
                }
            }
        }
        ans[u] = temp[labels[u] - 'a'];
        
        return temp;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        
        ans.resize(n);
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        DFS(adj, labels, 0, -1);
        
        return ans;
    }
};