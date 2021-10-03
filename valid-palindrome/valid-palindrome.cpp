class Solution {
public:
    bool isNotAlpha(char ch){
        if((ch>='0' && ch<='9') || (ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
            return false;
        }
        return true;
    }
    bool compare(char x,char y){
        if(tolower(x) == tolower(y)){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        
        while(i<j){
            while(i<j && isNotAlpha(s[i])){
                i++;
            }
            while(i<j && isNotAlpha(s[j])){
                j--;
            }
            if(!compare(s[i],s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};