class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int size = t.size();
        for(int i=size-2;i>=0;i--){
            int size2 = t[i].size();
            for(int j=0;j<size2;j++){
                t[i][j] += min(t[i+1][j],t[i+1][j+1]);
            }
        }
        return t[0][0];
    }
};