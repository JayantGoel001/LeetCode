#define pii pair<int,int>
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<pii> q;
        
        int n = graph.size();
        vector<int> vis(n,-1);
        
        for(int i=0;i<n;i++){
            if(vis[i] == -1){
                q.push({i,0});
                while(!q.empty()){
                    pii top = q.front();
                    q.pop();
                    
                    vis[top.first] = top.second;

                    for(auto it : graph[top.first]){
                        if(vis[it] == -1){
                            q.push({it,1 - top.second});
                        }else if(top.second == vis[it]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};