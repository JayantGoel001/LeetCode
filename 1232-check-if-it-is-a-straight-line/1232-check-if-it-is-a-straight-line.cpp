class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int x = c[0][0];
        int y = c[0][1];
        
        for(int i=1;i<c.size();i++){
            
            int x1 = c[i][0];
            int y1 = c[i][1];
            
            int x2 = c[i-1][0];
            int y2 = c[i-1][1];
            
            if((y - y2) * (x2 - x1) != (y2 - y1) * (x - x2)){
                return false;
            }
        }
        return true;
    }
};