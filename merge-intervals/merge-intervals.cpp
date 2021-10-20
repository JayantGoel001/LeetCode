class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(),intervals.end());
        for(auto it : intervals){
            if(merged.empty() || merged.back()[1] < it[0]){
                merged.push_back(it);
            }else{
                merged.back()[1] = max(merged.back()[1],it[1]);
            }
        }
        return merged;
    }
};