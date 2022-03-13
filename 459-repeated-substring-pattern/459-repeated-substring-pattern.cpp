class Solution {
public:
    bool checkRepeatedSubstring(string &s,string &str,int i,int n){
        bool res = true;
        int x = str.size();
        for(int j=i;j<n;j+=x){
            res &= s.substr(j,x) == str;
        }
        return res;
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        string str = "";
        for(int i=0;i<n;i++){
            str += s[i];
            
            if(str != s && checkRepeatedSubstring(s,str,i+1,n)){
                return true;
            }
        }
        return false;
    }
};