class Solution {
public:
    vector<int> mp;
    int DFS(vector<vector<int>> &adj, int u, vector<bool> &isVisited){
        isVisited[u] = true;
        
        int mini = u;
        
        for(auto it : adj[u]){
            if(!isVisited[it]){
                mini = min(mini, DFS(adj, it, isVisited));
            }
        }
        return mini;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int>> v(26);
        for(int i=0;i<s1.size();i++){
            v[s1[i] - 'a'].push_back(s2[i] - 'a');
            v[s2[i] - 'a'].push_back(s1[i] - 'a');
        }
        
        string str = "";
        mp.resize(26, -1);
        for(auto it : baseStr){
            if(mp[it - 'a'] == -1){
                vector<bool> isVisited(26, false);
                mp[it - 'a'] = (DFS(v, it - 'a', isVisited) + 'a');
            }
            str += mp[it - 'a'];
        }
        return str;
    }
};