class Solution {
public:
    string reversePrefix(string word, char ch) {
        string str = "";
        bool found = false;
        
        for(auto it : word){
            if(it == ch){
                found = true;
                break;
            }
        }
        if(!found){
            return word;
        }
        found = false;
        
        for(auto it : word){
            if(found == false){
                str = it + str;
            }else{
                str += it;
            }
            if(it == ch){
                found = true;
            }
        }
        return str;
    }
};