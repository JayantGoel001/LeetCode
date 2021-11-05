class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v[n + 1],rv[n + 1];
        for(auto it : trust){
            v[it[0]].push_back(it[1]);
            rv[it[1]].push_back(it[0]);
        }
        for(int i=1;i<=n;i++){
            if(v[i].empty() && rv[i].size() == n-1){
                return i;
            }
        }
        return -1;
    }
};