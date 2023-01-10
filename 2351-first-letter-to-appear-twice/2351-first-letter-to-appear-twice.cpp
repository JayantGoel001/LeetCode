class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> v(26, false);
        for(auto it : s){
            if(v[it - 'a']){
                return it;
            }
            v[it - 'a'] = true;
        }
        return ' ';
    }
};