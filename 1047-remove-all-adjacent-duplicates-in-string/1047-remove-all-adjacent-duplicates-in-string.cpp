class Solution {
public:
    string removeDuplicates(string s) {
        string str = "";
        
        int i = 0;
        while(i < s.size()){
            if(!str.empty() && str.back() == s[i]){
                str.pop_back();
            }else{
                str += s[i];
            }
            i++;
        }
        return str;
    }
};