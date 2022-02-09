class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(),intervals.end());
        for(auto interval : intervals){
            if(v.size()==0 || v.back()[1] < interval[0]){
                v.push_back(interval);
            }else{
                v.back()[1] = max(v.back()[1],interval[1]);
            }
        }
        return v;
    }
};