#define pii pair<int,int>
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int mini = INT_MAX;
        int ans = -1;
        
        for(int i=0;i<points.size();i++){
            if((points[i][0] == x || points[i][1] == y) && mini > abs(points[i][0] - x) + abs(points[i][1] - y)){
                mini = abs(points[i][0] - x) + abs(points[i][1] - y);
                ans = i;
            }
        }
        
        return ans;
    }
};