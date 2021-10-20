class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        
        string temp = "";
        for(auto it : s){
            if(it == ' '){
                if(temp != ""){
                    if(str == ""){
                        str = temp;   
                    }else{
                        str = temp+ " " + str;
                    }
                }
                temp = "";
            }else{
                temp += it;
            }
        }
        if(temp != ""){
            if(str == ""){
                str = temp;   
            }else{
                str = temp+ " " + str;
            }
        }
        return str;
    }
};