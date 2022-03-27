class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1,mp2;
        for(auto it : nums1){
            mp1[it]++;
        }
        for(auto it : nums2){
            mp2[it]++;
        }
        vector<int> v1;
        for(auto it : mp1){
            if(mp2[it.first]==0){
                v1.push_back(it.first);
            }
        }
        vector<int> v2;
        for(auto it : mp2){
            if(mp1[it.first]==0){
                v2.push_back(it.first);
            }
        }
        return {v1,v2};
    }
};