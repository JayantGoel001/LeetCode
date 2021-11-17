class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(),intervals.end());
        for(auto it : intervals){
            if(v.empty() || v.back()[1] < it[0]){
                v.push_back(it);
            }else{
                v.back()[1] = max(v.back()[1],it[1]);
            }
        }
        return v;
    }
};