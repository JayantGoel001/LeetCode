class Solution {
public:
    //approach 2
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.length();
        if (len == 0) return "";
        
        int cols = len / rows;
        string ans = "";
        
        // Each diagonal starts at (0, j) where j is the column index
        for (int j = 0; j < cols; j++) {
            for (int r = 0, c = j; r < rows && c < cols; r++, c++) {
                // Map 2D coordinates (r, c) back to 1D index
                ans.push_back(encodedText[r * cols + c]);
            }
        }
        
        // Remove trailing spaces as per problem constraints
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        
        return ans;
    }
};