class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        int prev = 0;
        int res = 0;
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] >= intervals[prev][1]){
                prev = i;
            }else{
                res++;
                
                if(intervals[i][1] < intervals[prev][1]){
                    prev = i;
                }
            }
        }
        return res;
    }
};