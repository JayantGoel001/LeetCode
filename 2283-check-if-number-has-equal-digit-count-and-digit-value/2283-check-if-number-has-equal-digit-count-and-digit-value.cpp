class Solution {
public:
    bool digitCount(string num) {
        vector<int> mp(10);
        for(auto it : num){
            mp[it - '0']++;
        }
        for(int i=0;i<num.size();i++){
            if(num[i] - '0' != mp[i]){
                return false;
            }
        }
        return true;
    }
};