class Solution {
public:
    int res = 0;
    int DFS(vector<vector<int>> &adj, string &s, int u){
        int first = 0;
        int second = 0;
        for(auto it : adj[u]){
            int x = DFS(adj, s, it);
            
            if(s[u] != s[it]){
                if(first == 0){
                    first = x;
                }else if(second == 0){
                    second = x;
                }else if(first < second){
                    if(x > first){
                        first = x;
                    }
                }else{
                    if(x > second){
                        second = x;
                    }
                }
            }
        }
        res = max(res, 1 + first + second);
        return max(first,second) + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> adj(parent.size());
        for(int i=1;i<parent.size();i++){
            adj[parent[i]].push_back(i);
        }
        int dfs = DFS(adj, s, 0);
        
        return res;
    }
};