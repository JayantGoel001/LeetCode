class Solution {
public:
    
    vector<int> calculateDistance(vector<int>& edges, int node){
        int n = edges.size();
        vector<int> dist(n, INT_MAX);
        dist[node] = 0;
        
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            if(edges[top] != -1 && dist[edges[top]] == INT_MAX){
                dist[edges[top]] = dist[top] + 1;
                
                q.push(edges[top]);
            }
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vector<int> v1 = calculateDistance(edges, node1);
        vector<int> v2 = calculateDistance(edges, node2);
        
        int index = 0;
        
        for(int i=0;i<n;i++){
            if(max(v1[index], v2[index]) > max(v1[i], v2[i])){
                index = i;
            }
        }
        
        return v1[index] == INT_MAX || v2[index] == INT_MAX ? -1 : index;
    }
};