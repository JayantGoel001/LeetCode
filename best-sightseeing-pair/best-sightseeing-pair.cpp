class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        
        int maxI = 0;
        int maxJ = 0;
        for(int i=0;i<n;i++){
            maxJ = max(maxJ,maxI + values[i] - i);
            maxI = max(maxI,values[i] + i);
        }
        
        return maxJ;
    }
};