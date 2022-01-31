class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        vector<int> initial = points[0];
        int size = points.size();
        
        for(int i=1;i<size;i++){
            time += max(abs(points[i][0] - initial[0]), abs(points[i][1] - initial[1]));
            
            initial = points[i];
        }
        return time;
    }
};