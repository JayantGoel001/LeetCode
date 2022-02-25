// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define pii pair<int,int>
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<int> dis(V,INT_MAX);
        dis[0] = 0;
        vector<int> vis(V,false);
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            pii top = pq.top();
            pq.pop();
            
            vis[top.second] = true;
            
            for(auto it : adj[top.second]){
                if(!vis[it[0]] && dis[it[0]] > it[1]){
                    dis[it[0]] = it[1];
                    pq.push({it[1],it[0]});
                }
            }
        }
        int w = 0;
        for(auto it : dis){
            w += it;
        }
        return w;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends