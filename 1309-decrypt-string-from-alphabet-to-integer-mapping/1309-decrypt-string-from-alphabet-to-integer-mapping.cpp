class Solution {
public:
    string freqAlphabets(string s) {
        string str = "";
        for(int i=0;i<s.size();i++){
            if(i + 2 < s.size() && s[i + 2] == '#'){
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

                str += (num - 1 + 'a');
                i++;
            }else if(s[i] != '#'){
                str += (s[i] - '0' - 1 + 'a');
            }
        }
        return str;
    }
};