class Solution {
public:
    int DFS(vector<vector<int>> &v, vector<bool> &hasApple, int u, int parent){
        int total = 0;
        
        for(auto it : v[u]){
            if(it != parent){
                int count = DFS(v, hasApple, it, u);
                
                if(count || hasApple[it]){
                    total += count + 2;
                }
            }
        }
        return total;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> v(n);
        for(auto it : edges){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        return DFS(v, hasApple, 0, -1);
    }
};