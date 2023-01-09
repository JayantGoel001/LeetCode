class Solution {
public:
    string sortSentence(string s) {
        string str = "";
        map<int,string> mp;
        
        for(auto it : s){
            if(it == ' '){
                char ch = str.back();
                str.pop_back();
                mp[ch] = str;
                str = "";
            }else{
                str += it;
            }
        }
        if(str != ""){
            char ch = str.back();
            str.pop_back();
            mp[ch] = str;
        }
        str = "";
        for(auto it : mp){
            str += it.second + " ";
        }
        str.pop_back();
        return str;
    }
};