#define pii pair<int,int>
class Solution {
public:
    bool isSafe(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    bool lives(vector<vector<int>> &board, int i, int j, vector<pii> &directions) {
        vector<int> cells(2, 0);
        for(auto dir : directions) {
            if (isSafe(i + dir.first, j + dir.second, board.size(), board[0].size())) {
                cells[board[i + dir.first][j + dir.second] % 2]++;
            }
        }
        return (board[i][j]%2==1 && (cells[1] == 2 || cells[1] == 3)) || (board[i][j]%2==0 && cells[1] == 3);
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<pii> directions = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0},
            {1, 1},
            {1, -1},
            {-1, 1},
            {-1,-1}
        };
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                board[i][j] += 2 * lives(board, i, j, directions);
            }
        }
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                board[i][j] /= 2;
            }
        }
    }
};