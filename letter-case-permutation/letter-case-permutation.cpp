class Solution {
public:
    
    int isNum(char a){
        return ( a >= '0' && a <= '9');
    }
    int islow(char a){
        return (a >= 'a' && a <= 'z');
    }
    
    
    void getPerm(int i, string &s, vector<string> &ans){
        
        if(i == s.size()){
            ans.push_back(s);
            return;
        }
        
        
        for(int j = i; j< s.size();j++){
            if(isNum(s[j])) {
                continue;
            }
            else if(islow(s[j])){
                
                s[j] = (s[j] - 'a') + 'A';
                getPerm(j+1, s, ans);
                
                s[j] = (s[j] - 'A') + 'a';
            }else{
                s[j] = (s[j] - 'A') + 'a';
                getPerm(j+1, s, ans);
                s[j] = (s[j] - 'a') + 'A';
            }
        }
        ans.push_back(s);
        return;
        
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        getPerm(0,s,ans);
        return ans;
    }
};