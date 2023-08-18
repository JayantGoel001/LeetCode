class Solution {
public:
    string finalString(string s) {
        string str = "";
        for(auto it : s){
            if(it == 'i'){
                reverse(str.begin(), str.end());
            }else{
                str += it;
            }
        }
        return str;
    }
};