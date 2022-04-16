class Solution {
public:
    static bool cmp(int p1,int p2){
        return p1 > p2;
    }
    vector<int> getPath(vector<int> v,int exclude){
        vector<int> res;
        for(int i=0;i<min((int)v.size(),3);i++){
            if(v[i] != exclude){
                res.push_back(v[i]);
            }
        }
        return res;
    }
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<int>> adj(n);
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            sort(adj[i].begin(),adj[i].end(),[&scores](int p1,int p2) -> bool{
                return scores[p1] > scores[p2];
            });
        }
        int maxScore = -1;
        for(auto it : edges){
            int initial = scores[it[0]] + scores[it[1]];
            vector<int> path1 = getPath(adj[it[0]], it[1]);
            vector<int> path2 = getPath(adj[it[1]], it[0]);
            
            for(auto p1 : path1){
                for(auto p2 : path2){
                    if(p1 != p2){
                        maxScore = max(maxScore, initial + scores[p1] + scores[p2]);
                    }
                }
            }
        }
        return maxScore;
    }
};