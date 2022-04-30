class Solution {
public:
    vector<vector<char>> ar;
    void verticalMove(int startX, int startY, int m, int n, int move){
        int px = startX + move;
        while (px >= 0 && px < m) {
            if (ar[px][startY] == 'E') {
                ar[px][startY] = 'V';
            } else if (ar[px][startY] == 'V' || ar[px][startY] == 'G' || ar[px][startY] == 'W'){
                break;
            }
            px += move;
        }
    }

    void horizontalMove(int startX, int startY, int m, int n, int move){
        int py = startY + move;
        while (py >= 0 && py < n) {
            if (ar[startX][py] == 'E') {
                ar[startX][py] = 'H';
            } else if (ar[startX][py] == 'H' || ar[startX][py] == 'G' || ar[startX][py] == 'W'){
                break;
            }
            py += move;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        ar.resize(m,vector<char> (n,'E'));
        for(auto it : walls){
            ar[it[0]][it[1]] = 'W';
        }
        
        for(auto it : guards){
            ar[it[0]][it[1]] = 'G';
            
            verticalMove(it[0], it[1], m, n, -1);
            verticalMove(it[0], it[1], m, n, 1);
            horizontalMove(it[0], it[1], m, n, 1);
            horizontalMove(it[0], it[1], m, n, -1);
        }
        
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                count += (ar[i][j] == 'E');
            }
        }
        return count;
    }
};