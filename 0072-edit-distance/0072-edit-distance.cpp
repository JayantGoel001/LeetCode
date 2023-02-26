class Solution {
public:
    vector<vector<int>> dp;
    int minDis(string &word1, string &word2, int i,int j){
        if(i == 0){
            return j;
        }
        if(j == 0){
            return i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(word1[i - 1] == word2[j - 1]){
            dp[i][j] = minDis(word1, word2, i - 1, j - 1);
        }else{
            dp[i][j] = 1 + min({minDis(word1, word2, i - 1, j - 1), minDis(word1, word2, i - 1, j), minDis(word1, word2, i, j - 1)});
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        dp.resize(word1.size() + 1, vector<int> (word2.size() + 1, -1));
        return minDis(word1, word2, word1.size(), word2.size());
    }
};