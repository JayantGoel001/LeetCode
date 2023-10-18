//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int i,vector<int>adj[],int n,vector<int>&vis,set<int>&ans){
        vis[i] = 1;
        bool f = true;
        for(auto child:adj[i]){
            if(vis[child]==1){
                return false;
            }
            else{
                f&=dfs(child,adj,n,vis,ans);
            }
        }
        vis[i] = 0;
        if(f==true){
            ans.insert(i);
        }
        return f;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        set<int>ans;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,adj,V,vis,ans);
            }
        }
        
        vector<int>ans1;
        
        for(auto val:ans){ans1.push_back(val);}
        return ans1;
    }

};


//{ Driver Code Starts.

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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends