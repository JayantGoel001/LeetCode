class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        int i = 0;
        int size = intervals.size();
        while(i < size && intervals[i][1] < newInterval[0]){
            merged.push_back(intervals[i++]);
        }
        
        while(i < size && intervals[i][0] <= newInterval[1]){
            newInterval = {min(newInterval[0],intervals[i][0]),max(newInterval[1],intervals[i][1])};
            i++;
        }
        merged.push_back(newInterval);
        while(i < size){
            merged.push_back(intervals[i++]);
        }
        return merged;
    }
};