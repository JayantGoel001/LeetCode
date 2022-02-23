// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    vector<bool> vis;
    bool DFS(vector<int> adj[],int x,int parent = -1){
        vis[x] = true;
        
        for(auto it : adj[x]){
            if(!vis[it]){
                if(DFS(adj,it,x)){
                    return true;
                }
            }else if(parent != it){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vis.resize(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i] && DFS(adj,i)){
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends