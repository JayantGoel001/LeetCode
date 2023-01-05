class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int prev = points[0][1];
        int count = 0;
        
        for(auto it : points){
            if(prev >= it[0]){
                prev = min(it[1], prev);
            }else{
                count++;
                prev = it[1];
            }
        }
        return count+1;
    }
};