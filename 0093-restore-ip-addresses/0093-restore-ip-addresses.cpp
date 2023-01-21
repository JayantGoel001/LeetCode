class Solution {
public:
    bool isValid(string &s){
        if(s.size() != 1 && s[0] == '0'){
            return false;
        }
        return stoi(s) >= 0 && stoi(s) <= 255;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        for(int i = 1;i <= 3;i++){
            for(int j = 1;j <= 3;j++){
                for(int k = 1;k <= 3;k++){
                    for(int l = 1;l <= 3;l++){
                        if(i + j + k + l == s.size()){
                            string w = s.substr(0,i);
                            
                            string x =  s.substr(i, j);
                            
                            string y = s.substr(i + j, k);
                            
                            string z = s.substr(i + j + k, l);
                            
                            if(isValid(w) && isValid(x) && isValid(y) && isValid(z)){
                                string str = w + '.' + x + '.' + y + '.' + z;
                                v.push_back(str);
                            }
                        }
                    }
                }
            }
        }
        return v;
    }
};