class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> maxi(2, 0);
        for(int i=0;i<mat.size();i++){
            int count = 0;
            for(auto it : mat[i]){
                count += it == 1;
            }
            if(maxi[1] < count){
                maxi[0] = i;
                maxi[1] = count;
            }
        }
        return maxi;
    }
};