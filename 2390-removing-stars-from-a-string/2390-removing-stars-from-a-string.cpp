class Solution {
public:
    string removeStars(string s) {
        string str = "";
        for(auto it : s){
            if(it == '*'){
                str.pop_back();
            }else{
                str.push_back(it);
            }
        }
        return str;
    }
};