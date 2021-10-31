class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        vector<int> dp(1001,-1);
        
        q.push(start);
        dp[start] = 0;
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto it : nums){
                vector<int> op = {x+it,x-it,x^it};
                for(auto it2 : op){
                    if(it2 == goal){
                        return dp[x]+1;
                    }
                    if(it2 >= 0 && it2 <= 1000 && dp[it2] == -1){
                        dp[it2] = dp[x]+1;
                        q.push(it2);
                    }
                }
            }
        }
        return -1;
    }
};