class Solution {
public:
    bool detectCapitalUse(string word) {
        int u = 0;
        int l = 0;
        int pos = -1;
        
        for(int i = 0;i<word.size();i++){
            char ch = word[i];
            
            if(ch >= 'A' && ch <= 'Z'){
                u++;
                pos = i;
            }
            
            l += (ch >= 'a' && ch <= 'z');
        }
        
        return u == word.size() || l == word.size() || (u == 1 && pos == 0);
    }
};