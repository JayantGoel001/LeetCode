class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &nums,int i,int j,int l,int r){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==j) return dp[i][j]= nums[i]*l*r;
        int _max=0;
        int temp;
        for(int k=i;k<=j;k++){
            int x= solve(nums,i,k-1,l,nums[k]);
            int y=solve(nums,k+1,j,nums[k],r);
            temp=x+y+nums[k]*l*r;
            if(_max<temp){
                 _max=temp;
            }
        }
        return dp[i][j]= _max;
    }
    int maxCoins(vector<int>& nums) {
        int n= nums.size();
        dp.assign(n,vector<int>(n,-1));
        return solve(nums,0,nums.size()-1,1,1);
    }
};