class Solution {
public:
    bool check(string &s, string &str){
        for(int i=0;i<str.size();i++){
            int ch = str[i];
            int n = i;
            for(int j=0;j < s.size() / str.size();j++){
                if(s[n] != ch){
                    return false;
                }
                n += str.size();
            }
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        string str = "";
        for(int i=0;i<min(str1.size(), str2.size());i++){
            if(str1[i] == str2[i]){
                str += str1[i];
            }else{
                break;
            }
        }
        while(str1.size() < str.size() || str2.size() < str.size()){
            str.pop_back();
        }
        while(str.size() > 0 && (str1.size() % str.size() != 0 || str2.size() % str.size() != 0 || !check(str1, str) || !check(str2, str))){
            str.pop_back();
        }
        return str;
    }
};