class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];}
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        
        int prev = points[0][1];
        int count = 0;
        
        for(auto it : points){
            if(prev < it[0]){
                count++;
                prev = max(prev, it[1]);
            }
        }
        return count+1;
    }
};