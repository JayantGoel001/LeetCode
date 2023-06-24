class Solution {
public:
  int tallestBillboard(vector<int>& rods) {
    int sum = 0;
    for (int rod : rods) {
      sum += rod;
    }
    int dp[sum + 1];
    dp[0] = 0;
    for (int i = 1; i <= sum; i++) {
      dp[i] = -1;
    }
    for (int rod : rods) {
      int dpCopy[sum + 1];
      copy(dp, dp + (sum + 1), dpCopy);
      for (int i = 0; i <= sum - rod; i++) {
        if (dpCopy[i] < 0) continue;
        dp[i + rod] = max(dp[i + rod], dpCopy[i]);
        dp[abs(i - rod)] = max(dp[abs(i - rod)], dpCopy[i] + min(i, rod));
      }
    }
    return dp[0];
  }
};