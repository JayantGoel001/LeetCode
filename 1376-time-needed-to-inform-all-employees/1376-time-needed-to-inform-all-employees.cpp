class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        for(int i=0;i<n;i++){
            res = max(res, DFS(i,manager,informTime));
        }
        return res;
    }
    int DFS(int u,vector<int>& manager, vector<int>& informTime){
        if(manager[u] != -1){
            informTime[u] += DFS(manager[u],manager,informTime);
            manager[u] = -1;
        }
        return informTime[u];
    }
};