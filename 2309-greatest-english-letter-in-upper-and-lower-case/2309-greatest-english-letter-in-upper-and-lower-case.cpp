class Solution {
public:
    string greatestLetter(string s) {
        int l[26],u[26];
        for(int i=0;i<26;i++){
            l[i] = 0;
            u[i] = 0;
        }
        for(auto it : s){
            if(it >= 'a' && it <= 'z'){
                l[it - 'a']++;
            }
            if(it >= 'A' && it <= 'Z'){
                u[it - 'A']++;
            }
        }
        string res = "";
        for(int i=25;i>=0;i--){
            if(l[i] && u[i]){
                res += (char)(i + 'A');
                return res;
            }
        }
        return res;
    }
};