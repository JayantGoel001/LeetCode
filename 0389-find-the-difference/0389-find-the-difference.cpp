class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26, 0);
        
        for(auto it : t){
            v[it - 'a']++;
        }
        for(auto it : s){
            v[it - 'a']--;
        }
        for(int i=0;i<26;i++){
            if(v[i] != 0){
                return i + 'a';
            }
        }
        return ' ';
    }
};