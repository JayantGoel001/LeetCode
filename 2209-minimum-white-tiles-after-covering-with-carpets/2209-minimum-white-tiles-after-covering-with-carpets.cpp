class Solution {
public:
    vector<vector<int>> dp;
    vector<int> whiteSum;
    
    int getCovered(int num,int len,int floorLen,int idx = 0){
        if(num <= 0){
            return 0;
        }
        if(floorLen - idx <= len){
            return whiteSum[floorLen - 1] - (idx == 0 ? 0 : whiteSum[idx - 1]);
        }
        if(dp[idx][num] == -1){
            dp[idx][num] = max(
                whiteSum[idx + len - 1] - (idx == 0 ? 0 : whiteSum[idx - 1]) + getCovered(num - 1,len,floorLen,idx + len),
                getCovered(num,len,floorLen,idx + 1)
            );
        }
        return dp[idx][num];
    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int white = 0;
        for(auto it : floor){
            white += (it == '1');
        }
        whiteSum.resize(floor.size(), 0);
        whiteSum[0] = (floor[0] == '1' ? 1 : 0);
        
        for(int i=1;i<floor.size();i++){
            whiteSum[i] = whiteSum[i - 1] + (floor[i] == '1' ? 1 : 0);    
        }
        dp.resize(floor.size(), vector<int> (numCarpets + 1, -1));
        return white - getCovered(numCarpets,carpetLen,floor.size());
    }
};