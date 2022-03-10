class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it : edges){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> v;
        for(int i=0;i<n;i++){
            if(adj[i].size() == 0){
                v.push_back(i);
            }
        }
        return v;
    }
};