class Solution {
public:
    string toLowerCase(string s) {
        string str = "";
        
        for(auto it : s){
            if(it >='A' && it <= 'Z'){
                str += (it + 32);
            }else{
                str += it;
            }
        }
        return str;
    }
};