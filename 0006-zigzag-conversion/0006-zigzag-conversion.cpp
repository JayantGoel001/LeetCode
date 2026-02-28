class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<vector<char>> v(numRows);
        int i = 0;
        bool forward = true;
        for(auto it : s) {
            v[i].push_back(it);

            if (forward) i++;
            else i--;

            if (i == numRows - 1 || i == 0) forward = !forward;
        }

        string str;
        for(int i=0;i<numRows;i++) {
            for(auto it : v[i]) str.push_back(it);
        }

        return str;
    }
};