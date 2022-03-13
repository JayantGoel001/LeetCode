class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> ar(n,vector<int> (n,0));
        for(auto it : dig){
            ar[it[0]][it[1]] = 1;
        }
        int count = 0;
        for(auto it : artifacts){
            int r1 = it[0];
            int r2 = it[2];
            int c1 = it[1];
            int c2 = it[3];
            int flag = true;
            for(int i=r1;i<=r2;i++){
                for(int j=c1;j<=c2;j++){
                    if(ar[i][j] == 0){
                        flag = false;
                        break;
                    }
                }
            }
            count += flag;
        }
        return count;
    }
};