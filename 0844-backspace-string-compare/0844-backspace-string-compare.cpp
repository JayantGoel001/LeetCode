class Solution {
public:
    void convert(string &x){
        for(int i=0;i<x.size();i++){
            if(x[i] == '#'){
                int start = i;
                while(start >= 0 && x[start] == '#'){
                    start--;
                }
                if(start >= 0){
                    x[start] = '#';
                }
            }
        }
    }
    bool backspaceCompare(string s, string t) {
        convert(s);
        convert(t);
        
        int i = 0;
        int j = 0;
        int cs = 0;
        int ct = 0;
        for(auto it : s){
            cs += it != '#';
        }
        for(auto it : t){
            ct += it != '#';
        }
        if(cs != ct){
            return false;
        }
        while(i < s.size() && j < t.size()){
            while(i < s.size() && s[i] == '#'){
                i++;
            }
            while(j < t.size() && t[j] == '#'){
                j++;
            }
            if(i < s.size() && j < t.size() && s[i] != t[j]){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};