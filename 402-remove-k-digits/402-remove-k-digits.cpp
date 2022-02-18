class Solution {
public:
    string removeKdigits(string num, int k) {
        string str;
        for(int i = 0;i < num.size();i++){
            while(k > 0 && str.size() && str.back() > num[i]){
                str.pop_back();
                k--;
            }
            if(str.size() || num[i]!='0'){
                str.push_back(num[i]);
            }
        }
        while(k > 0 && !str.empty()){
            str.pop_back();
            k--;
        }
        return str == "" ? "0" : str;
    }
};