class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v1(n + 1,0), v2(n + 1, 0);
        for(auto it: trust){
            v1[it[0]]++;
            v2[it[1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(v1[i] == 0 && v2[i] == n - 1){
                return i;
            }
        }
        return -1;
    }
};