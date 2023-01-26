#define pii pair<int,int>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pii>> adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, INT_MAX);
        
        dist[src] = 0;
        
        queue<pii> q;
        q.push({src, 0});
        
        int stop = 0;
        while(!q.empty() && stop <= k){
            int size = q.size();
            
            while(size--){
                pii top = q.front();
                q.pop();

                for(auto it : adj[top.first]){
                    if(dist[it.first] > top.second + it.second){
                        dist[it.first] = top.second + it.second;

                        q.push({it.first, dist[it.first]});
                    }
                }
            }
            stop++;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};