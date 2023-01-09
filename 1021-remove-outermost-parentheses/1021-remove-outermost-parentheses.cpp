class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string str = "";
        int o = 0;
        
        for(auto it : s){
            if(it == '(' && o++ > 0){
                str += it;
            }
            if(it == ')' && o-- > 1){
                str += it;
            }
        }
        return str;
    }
};