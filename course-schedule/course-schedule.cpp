class Solution {
public:
    unordered_map<int,int> isVis,parent;
    stack<int> st;
    
    bool cycle(vector<int> *adj,int num){
        isVis[num] = 1;
        parent[num] = 1;
        
        for(auto it : adj[num]){
            if((isVis[it] == 0 && cycle(adj,it)) || parent[it] == 1){
                return true;
            }
        }
        
        parent[num] = 0;
        return false;
    }
    
    bool detectCycle(vector<int> *adj,int num){
        for(int i=0;i<num;i++){
            if(isVis[i]==0 && cycle(adj,i)){
                return true;
            }
        }
        return false;
    }
    
    void topologicalSort(vector<int> *adj,stack<int> &st,int num){
        isVis[num] = true;
        
        for(auto it : adj[num]){
            if(isVis[it]==0){
                topologicalSort(adj,st,it);
            }
        }
        
        st.push(num);
    }
    
    int topoSort(vector<int> *adj,int num){
        stack<int> st;
        
        for(int i=0;i<num;i++){
            if(isVis[i]==0){
                topologicalSort(adj,st,i);
            }
        }
        return st.size();
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
        vector<int> adj[numCourses]; 
        
        for(auto it : pre){
            adj[it[0]].push_back(it[1]);
        }
        
        if(detectCycle(adj,numCourses)){
            return false;
        }
        isVis.clear();
        return topoSort(adj,numCourses) == numCourses;
    }
};