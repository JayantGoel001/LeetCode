class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;
        string str = "";
        for(auto it : s){
            if(str.size() == k){
                v.push_back(str);
                str = it;
            }else{
                str += it;
            }
        }
        if(str.size()){
            while(str.size() != k){
                str += fill;
            }
            v.push_back(str);
        }
        return v;
    }
};