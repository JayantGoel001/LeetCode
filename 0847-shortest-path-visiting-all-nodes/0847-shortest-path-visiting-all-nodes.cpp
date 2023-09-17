#define pii pair<int,int>
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        if(n == 1){
            return 0;
        }
        int x = (1 << n) - 1;
        
        vector<vector<bool>> vis(n,vector<bool> (x,false));
        queue<pii> q;
        int steps = 0;
        
        for(int i=0;i<n;i++){
            q.push({i, 1 << i});
            vis[i][1 << i] = true;
        }
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                pii top = q.front();
                q.pop();
                
                for(auto it : graph[top.first]){
                    int w = top.second | (1 << it);
                    if(w == x){
                        return 1 + steps;
                    }
                    
                    if(!vis[it][w]){
                        vis[it][w] = true;
                        q.push({it,w});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};