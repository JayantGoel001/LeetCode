class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int rsum = 0;
        for(auto it : nums){
            rsum += it;
        }
        int lsum = 0;
        vector<int> v;
        for(auto it : nums){
            rsum -= it;
            v.push_back(abs(rsum - lsum));
            lsum += it;
        }
        return v;
    }
};