class Solution {
public:
    void reverse(string &s){
        int size = s.size();
        for(int i=0;i<size/2;i++){
            swap(s[i],s[size-i-1]);
        }
    }
    string reverseWords(string s) {
        string temp = "";
        string str = "";
        for(auto it : s){
            if(it == ' '){
                reverse(temp);
                str.append(temp);
                str.append(" ");
                temp = "";
            }else{
                temp += it;
            }
        }
        reverse(temp);
        str.append(temp);
        return str;
    }
};