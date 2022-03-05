class Solution {
public:
    string interpret(string str) {
        int i = 0;
        int n = str.size();
        string res = "";
        
        while(i < n){
            if(str[i] == '('){
                string x = "";
                i++;
                while(i < n && str[i] != ')'){
                    x += str[i];
                    i++;
                }
                res.append(x == "" ? "o" : "al");
            }else{
                res += str[i];
            }
            i++;
        }
        return res;
    }
};