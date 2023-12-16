class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26, 0);
        
        for(auto it : s){
            v[it - 'a']++;
        }
        for(auto it : t){
            v[it - 'a']--;
        }
        for(auto it : v){
            if(it != 0){
                return false;
            }
        }
        return true;
    }
};