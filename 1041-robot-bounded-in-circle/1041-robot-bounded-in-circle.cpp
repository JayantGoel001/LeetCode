class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> dir = {{0,1}, {-1, 0}, {0, -1}, {1,0}};
        int i = 0;
        int x = 0;
        int y = 0;
       
        for(int s = 0; s < instructions.size(); s++){
            if(instructions.at(s) == 'L'){
                i = (i + 1) % 4;
            }
            else if(instructions.at(s) == 'R'){
                i = (i + 3) % 4;
            }
            else{
                x = x + dir[i][0];
                y = y + dir[i][1];
            }
        }
        return x == 0 && y == 0 || i != 0;
    }
};