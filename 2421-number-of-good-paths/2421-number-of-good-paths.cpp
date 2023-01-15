class Solution {
public:
    vector<int> parent, rank;
    
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void findUnion(int x,int y){
        int xset = find(x);
        int yset = find(y);
        
        if(xset == yset){
            return;
        }
        
        if(rank[xset] < rank[yset]){
            parent[xset] = yset;
        }else if(rank[xset] > rank[yset]){
            parent[yset] = xset;
        }else{
            parent[yset] = xset;
            rank[xset]++;
        }
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        vector<vector<int>> v(vals.size());
        for(auto it : edges){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        
        parent.resize(vals.size());
        rank.resize(vals.size(), 0);
        for(int i=0;i<parent.size();i++){
            parent[i] = i;
        }
        map<int, vector<int>> mp;
        for(int i = 0;i < vals.size(); i++){
            mp[vals[i]].push_back(i);
        }
        int paths = 0;
        for(auto it : mp){
            for(auto node : it.second){
                for(auto child : v[node]){
                    if(vals[node] >= vals[child]){
                        findUnion(node, child);
                    }
                }
            }
            unordered_map<int,int> ump;
            for(auto node : it.second){
                ump[find(node)]++;
            }
            for(auto it2 : ump){
                paths += (it2.second * (it2.second + 1))/2;
            }
        }
        return paths;
    }
};