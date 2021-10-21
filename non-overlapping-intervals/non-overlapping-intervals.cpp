class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        int res = 0;
        int pre = 0;
        
        int size = intervals.size();
        for(int i=1;i<size;i++){
            if(intervals[i][0] < intervals[pre][1]){
                res++;
                if(intervals[i][1] < intervals[pre][1]){
                    pre = i;
                }
            }else{
                pre = i;
            }
        }
        return res;
    }
};