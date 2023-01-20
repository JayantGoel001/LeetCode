class Solution {
public:
    string decode(string s,int &pos) {
        string res = "";
        
        while(pos < s.size() && s[pos] != ']'){
            if(s[pos] >= '0' && s[pos] <= '9'){
                int num = 0;

                while(pos < s.size() && s[pos] >= '0' && s[pos] <= '9'){
                    num = num * 10 + (s[pos] - '0');
                    pos++;
                }
                pos++;
                string t = decode(s, pos);
                pos++;
                
                while(num-- > 0){
                    res += t;
                }
            }else{
                res += s[pos++];
            }
        }
        return res;
    }
    string decodeString(string s) {
        int pos = 0;
        return decode(s,pos);
    }
};