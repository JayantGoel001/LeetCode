class Solution {
public:
    string convertToTitle(int col) {
        string str = "";
        
        while(col != 0){
            int x = col%26;
            if(x == 0){
                x = 26;
                col--;
            }
            str = (char)(x + 64) + str;
        
            col/=26;
        }
        return str;
    }
};