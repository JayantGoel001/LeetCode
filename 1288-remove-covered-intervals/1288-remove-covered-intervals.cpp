class Solution {
public:
    static bool cmp(vector<int> &i1,vector<int> &i2){
        return i1[0] == i2[0] ? i1[1] > i2[1] : i1[0] < i2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        
        int count = 0;
        int right = -1;
        for(auto it : intervals){
            if(it[1] > right){
                count++;
                right = it[1];
            }
        }
        return count;
    }
};