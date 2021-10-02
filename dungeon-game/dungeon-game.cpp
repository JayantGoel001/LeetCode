class Solution {
public:
    int dp[201][201];
    int getMinHP(vector<vector<int>>& dungeon,int i,int j,int n,int m){
        if(i == n-1 && j == m-1){
            return dungeon[i][j]<=0 ? abs(dungeon[i][j]) + 1 : 1;
        }
        if(i >= n){
            return INT_MAX;
        }
        if(j >= m){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int d = getMinHP(dungeon,i+1,j,n,m);
        int r = getMinHP(dungeon,i,j+1,n,m);
        
        int ans = min(d,r) - dungeon[i][j];
        dp[i][j] = ans > 0 ? ans : 1;
        
        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,-1,sizeof dp);
        
        int n = dungeon.size();
        int m = dungeon[0].size();
        
        return getMinHP(dungeon,0,0,n,m);
    }
};