// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    vector<bool> vis;
    vector<bool> res;
    
    bool cyclic(vector<int> adj[],int u){
        vis[u] = true;
        res[u] = true;
        
        for(auto it : adj[u]){
            if(!vis[it]){
                if(cyclic(adj,it)){
                    return true;
                }
            }else if(res[it]){
                return true;
            }
        }
        res[u] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vis.resize(V,false);
        res.resize(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i] && cyclic(adj,i)){
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends