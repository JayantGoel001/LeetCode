class Solution {
    unordered_map<int,vector<int> > gr;
    vector<int> vis;
    vector<int> colo;
public:
    bool dfs(int u){
        vis[u]=1;
        for(auto v:gr[u]){
            if(!vis[v]){
                colo[v]=1-colo[u];
                if(!dfs(v)){
                    return false;
                }
            }
            else if(colo[v]==colo[u]){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        for(auto d:dislikes){
            gr[d[0]].push_back(d[1]);
            gr[d[1]].push_back(d[0]);
        }
        colo.resize(N+1,-1);
        vis.resize(N+1,0);
        for(int i=1;i<=N;i++){
            if(colo[i]==-1){
                colo[i]=1;
                if(!dfs(i)){
                    return false;
                }
            }
        }
        return true;
    }
};