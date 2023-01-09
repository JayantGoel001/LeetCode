class Solution {
public:
    string sortString(string s) {
        map<char,int> mp;
        for(auto it : s){
            mp[it]++;
        }
        string str = "";
        bool flag = true;
        while(str.size() < s.size()){
            if(flag){
                for (auto it = mp.begin(); it != mp.end(); ++it){
                    if(it->second > 0){
                        str += it->first;
                        it->second-=1;
                    }
                }
            }else{
                for (auto it = mp.rbegin(); it != mp.rend(); ++it){
                    if(it->second > 0){
                        str += it->first;
                        it->second-=1;
                    }
                }
            }
            flag = !flag;
        }
        return str;
    }
};