class Solution {
public:
    int percentageLetter(string s, char letter) {
        int x = 0;
        for(auto it : s){
            x += (it == letter);
        }
        return x*100/s.size();
    }
};