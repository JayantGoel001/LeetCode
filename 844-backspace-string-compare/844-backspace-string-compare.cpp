class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int ss = s.size();
        int st = t.size();
        
        while(i >= 0 || j >= 0){
            int skipi = 0;
            while(i >= 0){
                if(s[i] == '#'){
                    skipi++;
                }else if(skipi > 0){
                    skipi--;
                }else{
                    break;
                }
                i--;
            }
            int skipj = 0;
            while(j >= 0){
                if(t[j] == '#'){
                    skipj++;
                }else if(skipj > 0){
                    skipj--;
                }else{
                    break;
                }
                j--;
            }
            if(i >=0 && j >=0 && s[i] != t[j]){
                return false;
            }
            if((i>=0) != (j >=0)){
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
};