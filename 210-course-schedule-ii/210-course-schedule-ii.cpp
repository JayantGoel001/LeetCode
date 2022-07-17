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
    
    stack<int> topoSort(vector<int> *adj,int num){
        stack<int> st;
        
        for(int i=0;i<num;i++){
            if(isVis[i]==0){
                topologicalSort(adj,st,i);
            }
        }
        return st;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        vector<int> adj[numCourses]; 
        
        for(auto it : pre){
            adj[it[1]].push_back(it[0]);
        }
        
        if(detectCycle(adj,numCourses)){
            return {};
        }
        isVis.clear();
        
        stack st = topoSort(adj,numCourses);
        
        if(st.size() != numCourses){
            return {};
        }
        vector<int> v;
        
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        return v;
    }
};