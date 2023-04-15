class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> dp(k + 1, 0);
        
        int sum = 0;
        for(auto pile : piles){
            for(int i=1;i<pile.size();i++){
                pile[i] += pile[i - 1];
            }
            sum = min(sum + (int)pile.size(), k);
            
            for(int j=sum;j>0;j--){
                for(int w=0;w < min((int)pile.size(), j);w++){
                    dp[j] = max(dp[j], dp[j - w - 1] + pile[w]);
                }
            }
        }
        return dp[k];
    }
};