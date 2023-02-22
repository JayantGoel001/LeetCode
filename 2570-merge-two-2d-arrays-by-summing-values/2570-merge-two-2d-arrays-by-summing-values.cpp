class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> v;
        int n = nums1.size();
        int m = nums2.size();
        
        int i = 0;
        int j = 0;
        
        while(i < n && j < m){
            if(nums1[i][0] == nums2[j][0]){
                v.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }else if(nums1[i][0] < nums2[j][0]){
                v.push_back(nums1[i++]);
            }else{
                v.push_back(nums2[j++]);
            }
        }
        while(i < n){
            v.push_back(nums1[i++]);
        }
        while(j < m){
            v.push_back(nums2[j++]);
        }
        return v;
    }
};