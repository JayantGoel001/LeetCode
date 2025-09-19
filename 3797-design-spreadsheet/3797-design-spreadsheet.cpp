class Spreadsheet {
    vector<vector<int>> cells;
public:
    Spreadsheet(int rows) {
        cells = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        cells[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        cells[row][col] = 0;
    }
    
    int getValue(string formula) {
        int idx = formula.find('+');
        string left = formula.substr(1, idx - 1);
        string right = formula.substr(idx + 1);

        int valLeft = 
            isalpha(left[0]) 
            ? cells[stoi(left.substr(1)) - 1][left[0] - 'A'] 
            : stoi(left);

        int valRight = 
            isalpha(right[0]) 
            ? cells[stoi(right.substr(1)) - 1][right[0] - 'A'] 
            : stoi(right);

        return valLeft + valRight;
    }
};