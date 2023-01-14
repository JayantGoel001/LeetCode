class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<vector<bool>> v(3, vector<bool> (101,false));
        
        for(auto it : nums1){
            v[0][it] = true;
        }
        for(auto it : nums2){
            v[1][it] = true;
        }
        for(auto it : nums3){
            v[2][it] = true;
        }
        vector<int> res;
        for(int i=0;i<=100;i++){
            if(v[0][i] + v[1][i] + v[2][i] >=2){
                res.push_back(i);
            }
        }
        return res;
    }
};