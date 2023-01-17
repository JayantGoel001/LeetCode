class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zeros = 0;
        
        for(auto it : s){
            zeros += it == '0';
        }
        
        int _z = 0;
        int _o = 0;
        
        int mini = INT_MAX;
        for(int i=0;i<s.size();i++){
            mini = min(mini, zeros - _z + _o);
            _z += s[i] == '0';
            _o += s[i] == '1';
        }
        mini = min(mini, zeros - _z + _o);
        return mini;
    }
};