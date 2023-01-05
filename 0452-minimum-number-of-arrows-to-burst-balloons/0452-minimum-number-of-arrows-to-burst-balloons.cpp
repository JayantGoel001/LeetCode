class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        vector<int> prev = points[0];
        int count = 0;
        
        for(auto it : points){
            if(prev[1] >= it[0]){
                prev = {it[0], min(it[1], prev[1])};
            }else{
                count++;
                prev = it;
            }
        }
        return count+1;
    }
};