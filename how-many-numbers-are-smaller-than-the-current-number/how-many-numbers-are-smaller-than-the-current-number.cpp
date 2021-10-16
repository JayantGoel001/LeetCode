class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums;
        vector<int> v;
        sort(temp.begin(),temp.end());
        
        for(auto it : nums){
            int pos = lower_bound(temp.begin(),temp.end(),it) - temp.begin();
            v.push_back(pos);
        }
        return v;
    }
};