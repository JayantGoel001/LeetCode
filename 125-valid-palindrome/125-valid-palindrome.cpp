class Solution {
public:
    bool isAN(char x){
        return (x >= 'a' && x <= 'z') || ('A' <= x && x <= 'Z') || ('0' <= x && x <= '9');
    }
    bool equalIgnoreCase(char x,char y){
        if(x >= 'A' && x <='Z'){
            x += 32;
        }
        if(y >= 'A' && y <= 'Z'){
            y += 32;
        }
        return x == y;
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        
        while(i < j){
            while(i < j && !isAN(s[i])){
                i++;
            }
            while(i < j && !isAN(s[j])){
                j--;
            }
            if(!equalIgnoreCase(s[i],s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};