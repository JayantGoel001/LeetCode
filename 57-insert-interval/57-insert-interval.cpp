class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        bool inserted = false;
        for(auto it : intervals){
            if(it[0] > newInterval[0] && !inserted){
                merged.push_back(newInterval);
                inserted = true;
            }
            merged.push_back(it);
        }
        if(!inserted){
            merged.push_back(newInterval);
        }
        intervals.clear();
        
        for(auto it : merged){
            if(intervals.empty() || intervals.back()[1] < it[0]){
                intervals.push_back(it);
            }else{
                intervals.back()[1] = max(intervals.back()[1],it[1]);
            }
        }
        return intervals;
    }
};