class Solution {
public:
    int countAsterisks(string s) {
        bool dash = false;
        
        int count = 0;
        for(auto it : s){
            if(it == '|'){
                dash = !dash;
            }
            if(it == '*'){
                count += (dash == false);
            }
        }
        return count;
    }
};