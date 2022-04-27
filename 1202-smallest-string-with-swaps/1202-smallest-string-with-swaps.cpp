class Solution {
public:
    vector<int> indices;
    vector<bool> visited;
    vector<vector<int>> adjList;
    string indiceString;
    void dfs(string &s,int n){
        visited[n]=true;
        indices.push_back(n);
        indiceString+=s[n];
        for(int &i:adjList[n])
            if(!visited[i])
               dfs(s,i);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        adjList.resize(s.length());
        visited.resize(s.length(),false);
        for(vector<int> &v:pairs)
            adjList[v[0]].push_back(v[1]),adjList[v[1]].push_back(v[0]);
        for(int i=0;i<s.length();i++)
            if(!visited[i]){
                indiceString="";
                indices.clear();
                dfs(s,i);
                sort(indiceString.begin(),indiceString.end());
                sort(indices.begin(),indices.end());
                for(int i=0;i<indices.size();i++)          
                    s[indices[i]]=indiceString[i];
            }
        return s;
    }
};