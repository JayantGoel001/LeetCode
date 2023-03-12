class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> v(26, 0);
        for(auto it : word1){
            v[it - 'a']++;
        }
        for(auto it : word2){
            v[it - 'a']--;
        }
        int count = 0;
        for(auto it : v){
            if(abs(it) > 3){
                return false;
            }
        }
        return true;
    }
};